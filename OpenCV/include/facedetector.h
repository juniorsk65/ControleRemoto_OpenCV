#ifndef FACEDETECTOR_H
#define FACEDETECTOR_H

#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <string>
#include <mutex>

class Facedetector{
    private:
        

    public:
        int xis,ypslon,raiou;
        int camera = 1;
        Facedetector(){}
        ~Facedetector(){}

        void detectAndDraw( cv::Mat& img, cv::CascadeClassifier& cascade,
                    cv::CascadeClassifier& nestedCascade,
                    double scale, bool tryflip );
        int run();
        int getXis(){return xis;}
        int getYpslon(){return ypslon;}
        std::mutex mutex;
        
};
#endif // FACEDETECTOR_H