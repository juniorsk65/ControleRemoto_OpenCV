#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

class Facedetector{
    private:
        

    public:
        int xis,ypslon,raiou;
        Facedetector(){}
        ~Facedetector(){}

        void detectAndDraw( cv::Mat& img, cv::CascadeClassifier& cascade,
                    cv::CascadeClassifier& nestedCascade,
                    double scale, bool tryflip );

};

#endif // FACEDETECTOR_H  