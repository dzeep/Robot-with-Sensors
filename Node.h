#pragma once

/**
* @file Path.h
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief The node class has been created.
*/
#include "Pose.h"
/*!
* \struct Node
* \brief Contains parts of the linked list.
*/
struct Node
{
	Node* next;
	Pose pose;
};