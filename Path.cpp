#include "Path.h"

Path::Path() {
	this->head = NULL;
	this->tail = NULL;
}
/*!
* \brief Adds the given pos location to the end of the list.
* @param pose is Pose variable.
* @return nothing.
*/
bool Path::addPos(Pose *pose) {
	Node* node = new Node();
	node->pose = *pose;
	if (node == NULL)
		return false;
	else 
	{
		node->next = NULL;
		if (this->head == NULL) {
			this->head = node;
			this->tail = node;
		}
		else {
			this->tail->next = node;
			this->tail = node;
		}
	}
	this->number++;
	return true;
}
/*!
* \brief Prints the locations in the list on the screen in a neat format.
* @return nothing.
*/
void Path::print() {
	float x, y, th;
	Node* node = this->head;
	node->pose.getPose(x, y, th);
	cout << x << "," << y << "," << th << endl;
	while (node->next != NULL) {	
		node = node->next;
		node->pose.getPose(x, y, th);
		cout << x << "," << y << "," << th << endl;
	}
	if (this->head->next == NULL){
		this->tail->pose.getPose(x, y, th);
		cout << x << "," << y << "," << th << endl;
	}
}
/*!
* \brief returns the position in the given index.
* @param i is int variable.
* @return path.
*/
Node Path::operator[](int i) {

	Node* path = this->head;

	for (int c = 0; c < this->number; c++) {
		if (i == c) 
			break;
		else 
			path = path->next;
	}
	return *path;
}
/*!
* \brief returns the position in the given index.
* @param index is int variable.
* @return this[index].getPos(index).
*/
Pose Path::getPos(int index) {	
	return this[index].getPos(index);
}
/*!
* \brief Deletes the position in the given index from the list.
* @param index is int variable.
* @return true or false.
*/
bool Path::removePos(int index) { //burada return false sıkıntı.
	Node* temp1 = head;
	if (index == 0) {
		head = temp1->next;
		free(temp1);
		return true;
	}
	for (int i = 0; i < index-1; i++)
		temp1 = temp1->next;

	//temp1 points to (n-1)th Node
	Node* temp2 = temp1->next; //nth Node
	temp1->next = temp2->next; //(n+1)th Node
	free(temp2);
	
	this->number--;

	return false;
}
/*!
* \brief Adds a position after the given index.
* @param index is int variable and @param pose is Pose variable.
* @return true or false.
*/
bool Path::insertPos(int index, Pose pose) {

	Node* temp = new Node();
	temp->pose = pose;
	temp->next = NULL;

	if (this->head == NULL) {
		this->head = temp;
		this->tail = temp;
		return true;
	}

	if (index == 0){
		temp->next = this->head;
		this->head = temp;
		return true;
	}

	Node* temp2 = this->head;
	for (int i = 0; i < index-1; i++){
		temp2 = temp2->next;
	}

	temp->next = temp2->next;
	temp2->next = temp;
	delete temp;

	this->number++;
	return true;	
}
/*!
* \brief print performs the task that the function does.
* @param out is ostream& variable and @param path is Path variable. 
* @return out.
*/
ostream& operator<<(ostream& out, Path path) {
	float x, y, th;
	Node* node = path.head;
	node->pose.getPose(x, y, th);
	out << x << "," << y << "," << th << endl;
	while (node->next != NULL) {
		node = node->next;
		node->pose.getPose(x, y, th);
		out << x << "," << y << "," << th << endl;
	}
	if (path.head->next == NULL) {
		path.tail->pose.getPose(x, y, th);
		out << x << "," << y << "," << th << endl;
	}

	return out;
}
/*!
* \brief Adds the location entered from the keyboard to the end of the list.
* @param in is istream& variable and @param path is Path variable.
* @return out.
*/
istream& operator>>(istream& in, Path path) {

	Pose* pose = new Pose();
	float _x, _y, _th;
	in >> _x >> _y >> _th;
	pose->setPose(_x, _y, _th);
	path.addPos(pose);

	return in;
}

int Path::getNumber() {
	return this->number;
}