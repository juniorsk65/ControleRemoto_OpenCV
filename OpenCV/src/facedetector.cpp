#include "../include/facedetector.h"

using namespace std;
using namespace cv;

string cascadeName;
string nestedCascadeName;

int Facedetector::run()
{   
    /*int argc = 1;
    const char** argv;
    argv[1] = "--cascade=haarcascade_frontalface_alt.xml"; */
    VideoCapture capture;
    Mat frame, image;
    //string inputName;
    bool tryflip;
    CascadeClassifier cascade, nestedCascade;
    double scale;

    //cascadeName =  parser.get<string>("cascade");
    cascadeName =  ("haarcascade_frontalface_alt.xml");
    scale = 1;
    if (scale < 1)
        scale = 1;
    if( !cascade.load( cascadeName ) )
    {
        cerr << "ERROR: Could not load classifier cascade" << endl;
        return -1;
    }
    if(!capture.open(camera))
            cout << "Capture from camera #" <<  camera << " didn't work" << endl;

    if( capture.isOpened() )
    {
        cout << "Video capturing has been started ..." << endl;
        for(;;)
        {
            capture >> frame;
            if( frame.empty() )
                break;

            Mat frame1 = frame.clone();
            detectAndDraw( frame1, cascade, nestedCascade, scale, tryflip );
            char c = (char)waitKey(10);
            if( c == 27 || c == 'q' || c == 'Q' )
                break;
        }
    }
    else
    {
        if( !image.empty() )
        {
            detectAndDraw( image, cascade, nestedCascade, scale, tryflip );
            waitKey(0);
        }
    }
    return 0;
}

void Facedetector::detectAndDraw( Mat& img, CascadeClassifier& cascade,
                    CascadeClassifier& nestedCascade,
                    double scale, bool tryflip )
{
    double t = 0;
    vector<Rect> faces, faces2;
    const static Scalar colors[] =
    {
        Scalar(255,0,0),
        Scalar(255,128,0),
        Scalar(255,255,0),
        Scalar(0,255,0),
        Scalar(0,128,255),
        Scalar(0,255,255),
        Scalar(0,0,255),
        Scalar(255,0,255)
    };
    Mat gray, smallImg;

    cvtColor( img, gray, COLOR_BGR2GRAY );
    double fx = 1 / scale;
    resize( gray, smallImg, Size(), fx, fx, INTER_LINEAR );
    equalizeHist( smallImg, smallImg );

    t = (double)getTickCount();
    cascade.detectMultiScale( smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        |CASCADE_SCALE_IMAGE,
        Size(30, 30) );

    t = (double)getTickCount() - t;
    
    for ( size_t i = 0; i < faces.size(); i++ )
    {
        Rect r = faces[i];
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = colors[i%8];
        int radius;

        //O cout abaixo esta mostrando no terminal as coordenadas(x,y) do centro da circunferencia onde foi encontrado o rosto
        //ele apenas imprime quando a circunferencia for estabelecida
        double aspect_ratio = (double)r.width/r.height;
        if( 0.75 < aspect_ratio && aspect_ratio < 1.3 )
        {
            center.x = cvRound((r.x + r.width*0.5)*scale);
            center.y = cvRound((r.y + r.height*0.5)*scale);
            radius = cvRound((r.width + r.height)*0.25*scale);
            circle( img, center, radius, color, 3, 8, 0 );
            //cout << "\n" << cvRound((r.x + r.width*0.5)*scale) << "X" << cvRound((r.y + r.height*0.5)*scale) << endl;
            xis = cvRound((r.x + r.width*0.5)*scale);
            ypslon = cvRound((r.y + r.height*0.5)*scale);  
            raiou = cvRound((r.width + r.height*0.5)*scale); 
            cout << xis << "X" << ypslon << "   " << raiou << endl;        
        }
    }
    imshow( "result", img );
}