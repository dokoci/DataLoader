#include "ofApp.h"

// SplitString Function by Theo
// this should be outside the setup()
static vector<string> splitString(const string &s, char delim) {
    stringstream ss(s);
    string item;
    vector<string> tokens;
    while (getline(ss, item, delim)) {
        tokens.push_back(item);
    }
    return tokens;
}

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetLogLevel(OF_LOG_VERBOSE); // Logs
    ofSetFrameRate(60); // set the framerate
    ofBackground(0); // Black background
    ofEnableDepthTest(); // enable 3D

    mesh.setMode(OF_PRIMITIVE_POINTS); // change the primitve mode here eg: OF_PRIMITIVE_LINES etc..
    glPointSize(1.5); // the size of point
    
    //auto buffer = ofSplitString(ofBufferFromFile("sheet.txt"),"," , ",");
    auto buffer = ofBufferFromFile("sheet.txt");
      for( auto line : buffer.getLines() ){
        //auto arr = ofSplitString(line, ",", false, true);
          auto arr = splitString(line, ',');
         
        if( arr.size() >= 3 ){
          float x = ofToFloat(arr[0]);
          float y = ofToFloat(arr[1]);
          float z = ofToFloat(arr[2]);
          glm::vec3 tempVert(x,y,z);
            mesh.addVertex(tempVert);
        }
      }
    
    mesh.setupIndicesAuto();
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSetWindowTitle(ofToString((int)ofGetFrameRate()));
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackgroundGradient(ofColor::gray, ofColor::black);
    
    cam.begin();
    //ofPushMatrix();
    ofSetColor(255, 255, 255);
    mesh.draw();
    //ofPopMatrix();
    cam.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
//        if(key == '1'){
//                mRenderer.start();
//        }else if(key == '2'){
//                mRenderer.stop();
//        }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ }
