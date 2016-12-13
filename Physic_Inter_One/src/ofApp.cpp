#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    numInputs = 16;
    minLength = 5;
    newSeq = false;
    
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
                pressesLog.push_back(allButs[i]);
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
    
    
    //look for recurring sequences in the input string that are at least "minLength" long
    for(int i = 0; i < pressesLog.size(); i++){
        for(int j = 0; j < pressesLog.size(); j++){
            if(j != i){
                if(pressesLog[i].getInputNumber() == pressesLog[j].getInputNumber()){
                    vector <butPres> tmpLog;
                    cout << "checking now: ";
                    int counter = 0;
                    if(j + minLength < pressesLog.size()){
                        for(int h = 0; h < (pressesLog.size() - j); h++){
                            if(pressesLog[j+h].getInputNumber() == pressesLog[i+h].getInputNumber()){
                                tmpLog.push_back(pressesLog[j+h]);
                                counter++;
                            }else{
                                break;
                            }
                        }
                        if(counter < minLength){
                            tmpLog.clear();
                        }else{
                            tmpLogs.push_back(tmpLog);
                            newSeq = true;
                            pressesLog.clear();
                        }
                    }
                }
            }
        }
    }
    
    /*
    //look for sequence in the inputs:
    if(recording == true){
        for(int i = 0; i < pressesLog.size(); i++){
            pressesLogConst.push_back(pressesLog[i]);
            for(int j = i+3; j < pressesLog.size(); j++){
                if(pressesLog[i].getInputNumber() == pressesLog[j].getInputNumber()){
                    cout << "lol";
                    vector <butPres> tmpVec;
                    for(int h = i; h < j+1; h++){
                        tmpVec.push_back(pressesLog[h]);
                    }
                    if(pressesLog[j].getInputNumber() == pressesLog[j+1].getInputNumber()){
                        tmpVec.push_back(pressesLog[j+1]);
                    }
                    tmpLogs.push_back(tmpVec);
                    pressesLog.clear();
                }
            }
        }
    }
    */
    //sync previnputs
    
    if(newSeq == true){
        
        //compare the latest sequence to all the ones already in the vector;
        
        newSeq = false;
    }
    
    
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
    for(int i = 0; i < tmpLogs.size(); i++){
        string tmpStr;
        for(int j = 0; j < tmpLogs[i].size(); j++){
            tmpStr += ", "+ofToString(tmpLogs[i][j].getInputNumber());
        }
        ofDrawBitmapString(tmpStr, 50, 400 + 20*i);
    }
    for(int i = 0; i < pressesLog.size(); i++){
        tmpString += ofToString(pressesLog[i].getInputNumber()) + ", ";
    }
    ofDrawBitmapString(tmpString, 300, 400);
    tmpString.clear();

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
