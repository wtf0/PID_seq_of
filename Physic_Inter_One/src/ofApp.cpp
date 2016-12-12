#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    numInputs = 16;
    
    inputs.resize(numInputs);
    prevInputs.resize(numInputs);
    inputCounter.resize(numInputs);
    allButs.resize(numInputs);
    isSingle.resize(numInputs);
    for(int i = 0; i < inputs.size(); i++){
        inputs[i] = false;
        prevInputs[i] = false;
        isSingle[i] = true;
        inputCounter[i] = 0;
    }
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i < inputs.size(); i++){
        if(inputs[i] == true && recording == false){
            recording = true;
        }
        if(prevInputs[i] == true){
            if(inputs[i] == false){
                inputCounter[i]++;
                allButs[i].setEndTime(ofGetElapsedTimef());
                cout<<"button logged yo, it stayed on for "+ofToString(allButs[i].getInterval())+" it was button: "+ofToString(allButs[i].getInputNumber());
            }
        }
    }
    
    //figure out how to recognise patterns//
    
    for(int i = 0; i < numInputs; i++){
        if(inputs[i] == true){
            if(prevInputs[i] == false){
                butPres tmpBut;
                tmpBut.setInputNumber(i);
                tmpBut.setStartTime(ofGetElapsedTimef());
                allButs[i] = tmpBut;
            }
        }
    }
    
    //sync previnputs
    prevInputs = inputs;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundColor(0,0,0);
    
    float startX = 50;
    float startY = 50;
    
    for(int i = 0; i < 4; i++){
        for(int j =  0; j < 4; j++){
            if(inputs[j+4*i] == true){
                ofSetColor(255, 223, 0);
            }else{
                ofSetColor(255,255,255);
            }
            ofDrawRectangle(startX + startX * j, startY + startY*i, 45, 45);
        }
    }
    
    ofDrawBitmapString("input counters:", 600, 50);
    for(int h = 0; h < inputCounter.size(); h++){
        ofDrawBitmapString(ofToString(inputCounter[h]), 600, 70 + 20*h);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //keys as inputs for the moment
    if(key == '1'){
        inputs[0] = true;
    }
    if(key == '2'){
        inputs[1] = true;
    }
    if(key == '3'){
        inputs[2] = true;
    }
    if(key == '4'){
        inputs[3] = true;
    }
    if(key == 'q'){
        inputs[4] = true;
    }
    if(key == 'w'){
        inputs[5] = true;
    }
    if(key == 'e'){
        inputs[6] = true;
    }
    if(key == 'r'){
        inputs[7] = true;
    }
    if(key == 'a'){
        inputs[8] = true;
    }
    if(key == 's'){
        inputs[9] = true;
    }
    if(key == 'd'){
        inputs[10] = true;
    }
    if(key == 'f'){
        inputs[11] = true;
    }
    if(key == '`'){
        inputs[12] = true;
    }
    if(key == 'z'){
        inputs[13] = true;
    }
    if(key == 'x'){
        inputs[14] = true;
    }
    if(key == 'c'){
        inputs[15] = true;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if(key == '1'){
        inputs[0] = false;
    }
    if(key == '2'){
        inputs[1] = false;
    }
    if(key == '3'){
        inputs[2] = false;
    }
    if(key == '4'){
        inputs[3] = false;
    }
    if(key == 'q'){
        inputs[4] = false;
    }
    if(key == 'w'){
        inputs[5] = false;
    }
    if(key == 'e'){
        inputs[6] = false;
    }
    if(key == 'r'){
        inputs[7] = false;
    }
    if(key == 'a'){
        inputs[8] = false;
    }
    if(key == 's'){
        inputs[9] = false;
    }
    if(key == 'd'){
        inputs[10] = false;
    }
    if(key == 'f'){
        inputs[11] = false;
    }
    if(key == '`'){
        inputs[12] = false;
    }
    if(key == 'z'){
        inputs[13] = false;
    }
    if(key == 'x'){
        inputs[14] = false;
    }
    if(key == 'c'){
        inputs[15] = false;
    }
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
