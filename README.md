# OpenCV Face Blur
Simple OpenCV project to detect faces in Photos/Pictures and Videos/Webcams

## About
The algorithm is simple. First, the program detects faces on the screen(Videofile or image)
and then cut out the detected face. Next step is to blur the cropped image and paste it in original image.
The program allows you to switch between picture and webcam in real time.

## Requirements
* C++
* [OpenCV](https://github.com/opencv/opencv)

## Installing
* Download ZIP file of the repository
* Transfer files to your PC
* Open terminal and follow the steps:
 ```
 mkdir build
 cd build
 cmake ..
 ```
* After that:
 ```
 make
 ```
* See the result!
 ```
 ./Blurred
 ```

## Screenshots
![Alt text](https://github.com/Dobryak99/OpenCV_Face_Blur/blob/main/Screenshots/face.png)

![Alt text](https://github.com/Dobryak99/OpenCV_Face_Blur/blob/main/Screenshots/face2.png)

![Alt text](https://github.com/Dobryak99/OpenCV_Face_Blur/blob/main/Screenshots/face3.png)
