#ifndef APRILTAGFINDER_H
#define APRILTAGFINDER_H

#include <list>

// April tags detector and various families
#include "AprilTags/TagDetector.h"
#include "AprilTags/Tag16h5.h"
#include "AprilTags/Tag25h7.h"
#include "AprilTags/Tag25h9.h"
#include "AprilTags/Tag36h9.h"
#include "AprilTags/Tag36h11.h"

using namespace std;

class AprilTagFinder
{

    AprilTags::TagDetector* m_tagDetector;
    AprilTags::TagCodes m_tagCodes;

    bool m_draw; // draw image and April tag detections?
    bool m_timing; // print timing information for each tag extraction call

    int m_width; // image size in pixels
    int m_height;
    double m_tagSize; // April tag side length in meters of square black frame
    double m_fx; // camera focal length in pixels
    double m_fy;
    double m_px; // camera principal point
    double m_py;

    int m_deviceId; // camera id (in case of multiple cameras)

    list<string> m_imgNames;

    cv::VideoCapture m_cap;

    int m_exposure;
    int m_gain;
    int m_brightness;

    //Serial m_serial;

public:

    // default constructor
    AprilTagFinder()
            :
            // default settings, most can be modified through command line options (see below)
            m_tagDetector(NULL), m_tagCodes(AprilTags::tagCodes36h11),

            m_draw(false), m_timing(true),

            m_width(640), m_height(480), m_tagSize(0.166), m_fx(600), m_fy(600), m_px(
                    m_width / 2), m_py(m_height / 2), m_deviceId(0),

            m_exposure(-1), m_gain(-1), m_brightness(-1)
    {
    }

    // changing the tag family
    void setTagCodes(string s);

    // parse command line options to change default behavior
    void parseOptions(int argc, char* argv[]);

    void setup();

    void setupVideo();

    void print_detection(AprilTags::TagDetection& detection) const;

    void processImageGray(cv::Mat& image_gray);

    void processImage(cv::Mat& image,cv::Mat& image_gray);

    // Load and process a single image
    void loadImages();

    // Video or image processing?
    bool isVideo();

    // The processing loop where images are retrieved, tags detected,
    // and information about detections generated
    void loop();

};
#endif // APRILTAGFINDER_H
