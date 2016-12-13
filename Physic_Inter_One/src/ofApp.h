#pragma once

#include "ofMain.h"
#include "butPres.h"
#include "sequence.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

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
    
        vector <butPres> pressesLog;
        vector <butPres> pressesLogConst;
        vector <vector <butPres>> tmpLogs;
        vector <butPres> allButs;
        vector <int> seqCounter;
        vector <int> inputCounter;
        vector <bool> isSingle;
    
        vector <bool> inputs;
        vector <bool> prevInputs;
    
        bool newSeq;
    
        int numInputs;
        bool recording;
        string tmpString;
        int minLength;
};
