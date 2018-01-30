#pragma once

#include "ofMain.h"
#include "ofxDatGui.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void onChangeBackground(ofxDatGuiButtonEvent evt);
		void onRedChange(ofxDatGuiSliderEvent evt);
		void onGreenChange(ofxDatGuiSliderEvent evt);
		void onBlueChange(ofxDatGuiSliderEvent evt);
		void random_background();
		void random_triangle();
		void random_triangle_circ();
		ofVec2f getPointInCircle(float rad);
		void saveArtwork();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofImage     img;
		
};
