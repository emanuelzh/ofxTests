#include "ofApp.h"

ofxDatGui* gui;
ofxDatGuiButton* changeBackgroundButton;

//color sliders
ofxDatGuiSlider* r_slider;
ofxDatGuiSlider* g_slider;
ofxDatGuiSlider* b_slider;

//triangle factor
ofxDatGuiSlider* triangle_slider;

//triangle speed
ofxDatGuiSlider* triangle_speed;

//bgcolor
ofColor bgcolor;

//--------------------------------------------------------------
void ofApp::setup(){

	//set a background
	ofBackground(255, 255, 255);
	bgcolor = ofGetBackgroundColor();

	//mabye put the gui here
	gui = new ofxDatGui(ofxDatGuiAnchor::TOP_RIGHT);
	changeBackgroundButton = gui->addButton("Random background");
	gui->onButtonEvent(this, &ofApp::onChangeBackground);

	//add a separator
	gui->addBreak()->setHeight(10.0f);

	//color sliders
	r_slider = gui->addSlider("Red", 0, 255);
	g_slider = gui->addSlider("Green", 0, 255);
	b_slider = gui->addSlider("Blue", 0, 255);
	gui->addBreak()->setHeight(10.0f);
	triangle_slider = gui->addSlider("T Alpha", 10, 128);
	triangle_speed = gui->addSlider("T Speed", 5, 100);

	r_slider->onSliderEvent(this, &ofApp::onRedChange);
	g_slider->onSliderEvent(this, &ofApp::onGreenChange);
	b_slider->onSliderEvent(this, &ofApp::onBlueChange);

	ofSetBackgroundAuto(false); //disable automatic background redraw

	random_background();
	ofBackground(bgcolor);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	//samebg ?
	//ofBackground(bgcolor);

	if (ofGetFrameNum() % (int)(101 - triangle_speed->getValue()) == 0) {
		random_triangle();
	}
	
}

//------ GUI Events
void ofApp::onChangeBackground(ofxDatGuiButtonEvent evt) {
	
	random_background();

}

void ofApp::onRedChange(ofxDatGuiSliderEvent evt) {
	//update the colors
	bgcolor.r = evt.value;
	ofBackground(bgcolor);
}

void ofApp::onGreenChange(ofxDatGuiSliderEvent evt) {
	//update the colors
	bgcolor.g = evt.value;
	ofBackground(bgcolor);
}

void ofApp::onBlueChange(ofxDatGuiSliderEvent evt) {
	//update the colors
	bgcolor.b = evt.value;
	ofBackground(bgcolor);
}

//--- Helpers
void ofApp::random_background()
{
	//random background
	bgcolor.r = ofRandom(0, 255);
	bgcolor.g = ofRandom(0, 255);
	bgcolor.b = ofRandom(0, 255);

	//update sliders
	r_slider->setValue(bgcolor.r);
	g_slider->setValue(bgcolor.g);
	b_slider->setValue(bgcolor.b);

	ofBackground(bgcolor);
}

void ofApp::random_triangle(){

	ofVec2f a = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	ofVec2f b = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));
	ofVec2f c = ofVec2f(ofRandom(0, ofGetWidth()), ofRandom(0, ofGetHeight()));

	ofEnableAlphaBlending();
	ofSetColor(10, 10, 10, triangle_slider->getValue());
	ofNoFill();
	ofDrawTriangle(a,b,c);
	ofDisableAlphaBlending();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
