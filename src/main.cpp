#include <iostream>
#include <vector>
#include <opencv2/highgui.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>

void DetectAndBlur(cv::Mat & img, cv::CascadeClassifier & cascade, const char choice);

int main(int argc, const char * argv[])
{
    cv::Mat video_frame, img;
    cv::VideoCapture cap;
    //Face detection
    cv::CascadeClassifier cascade;
    cascade.load("./Resources/haarcascade_frontalface_default.xml");
    
    std::cout << "***************Navigation Panel***************\n"
    << "\"W\" - Use WebCam\n\"P\" - Use photo from galary(Default)\n\"Q\" - Quit\n";
    char choice = 'P';
    while(choice != 'q')
    {
        if(choice == 'w' || choice == 'W')
        {
            cap.open(0);            // Using default camera
            if(!cap.isOpened())
            {
                std::cerr << "Can't open Webcam\n";
                return EXIT_FAILURE;
            }
            while(true)
            {
                choice = 'w';
                cap.read(video_frame);
                cv::Mat img_clone = video_frame.clone();
                DetectAndBlur(img_clone, cascade, choice);
                cv::imshow("Blurred", img_clone);
                choice = static_cast<char>(cv::waitKey(1));
                if(choice == 'q' || choice == 'p')
                {
                    break;
                }
            }
            cap.release();
            cv::destroyAllWindows();
        }
        if(choice == 'p' || choice == 'P')
        {
            if(argc < 2)
            {
                img = cv::imread("./Resources/face.jpg");
            }else{
                img = cv::imread(argv[1]);
            }
            while(true)
            {
                cv::Mat img_clone = img.clone();
                DetectAndBlur(img_clone, cascade, choice);
                cv::imshow("Blurred", img_clone);
                choice = static_cast<char>(cv::waitKey(0));
                if(choice == 'q' || choice == 'w')
                {
                    break;
                }
            }
            cv::destroyAllWindows();
        }
    }
    return 0;
}

void DetectAndBlur(cv::Mat & img, cv::CascadeClassifier & cascade,const char choice)
{
    cv::Mat img_gray;
    std::vector<cv::Rect> features;
    
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cascade.detectMultiScale(img_gray, features);
    
    for(auto rect: features)
    {
        cv::Mat Blur_face(img, rect);               //Copy ROI(region of interest) from image
        cv::GaussianBlur(Blur_face, Blur_face, cv::Size(33,33), 100);    //Blur the image
        Blur_face.copyTo(img(cv::Rect(rect.x, rect.y, rect.width, rect.height)));   //Insert cropped image back to original
    }
    if(choice == 'W' || choice == 'w')
    {
        cv::putText(img, "\"W\" WebCam", cv::Point(10, img.rows - 30), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(255,255,255), 2);
    }
    if(choice == 'P' || choice == 'p')
    {
        cv::putText(img, "\"P\" Photo", cv::Point(10, img.rows - 30), cv::FONT_HERSHEY_PLAIN, 3, cv::Scalar(255,255,255), 2);
    }
}
