#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openframeworks");

	ofBackground(255);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	auto deg = ofGetFrameNum() * 0.666666666666666666 * 8;
	auto target = glm::vec2(275 * cos(deg * DEG_TO_RAD), 275 * sin(deg * DEG_TO_RAD));

	for (int x = -325; x <= 325; x += 25) {
		
		for (int y = -325; y <= 325; y += 25) {

			if (glm::length(glm::vec2(x, y)) <= 250 || glm::length(glm::vec2(x, y)) >= 300) {

				this->draw_arrow(glm::vec2(x, y), target, 13, ofColor(255), ofColor(0));
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_arrow(glm::vec2 location, glm::vec2 target, float size, ofColor fill_color, ofColor no_fill_color) {

	auto angle = std::atan2(target.y - location.y, target.x - location.x);

	ofSetColor(fill_color);
	ofFill();
	ofBeginShape();
	ofVertex(location + glm::vec2(size * cos(angle), size * sin(angle)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)));
	ofEndShape();

	ofBeginShape();
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25);
	ofEndShape();

	ofSetColor(no_fill_color);
	ofNoFill();
	ofBeginShape();
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)));
	ofVertex(location + glm::vec2(size * cos(angle), size * sin(angle)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)));
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25);
	ofEndShape();

	ofBeginShape();
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle - PI * 0.5), size * 0.5 * sin(angle - PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25 - glm::vec2(size * cos(angle), size * sin(angle)) * 0.5);
	ofVertex(location + glm::vec2(size * 0.5 * cos(angle + PI * 0.5), size * 0.5 * sin(angle + PI * 0.5)) * 0.25);
	ofEndShape();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}