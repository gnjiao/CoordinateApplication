#pragma once

#include "CoordinateOperatorDefine.h"
#include <vector>


/*
@brief: This is a class witch operating the whole coordinate system.
@author: JoMar
@date: 2016-06-12
*/
class CCoordinateOperator
{
public:
	CCoordinateOperator();
	virtual ~CCoordinateOperator();

	/*
	@brief: This is a func convert a position between two coordinate.
	@param[in]: origin - it's a coordinate preparing to convert.
	@param[in|out]: target - it's a coordinate convert to. The martix id of target have to be defined.
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned ConvertPosition(const DOBOT_POSITION &origin, DOBOT_POSITION &target);

	/*
	@brief: This is a func to modify the coordinate. If the coordinate isn't existence, it will create a new one.
	@note: Transition martix is base on the world coordinate. The convert sequence: translation->roll->ptich->yaw->zoom
	@param[in|out]: id - coordinate id. Func will renturn a new Id, when the id isn't existence in vector;
	@param[in]: t - translation martix.
	@param[in]: r - rotation martix.
	@param[in]: zoom
	@param[in]: str - string of note
	@param[in]: strSize - the size of string
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned SetCoordinate(unsigned &id, const E3_VECTOR &t, const E3_VECTOR &r, const double &zoom, const TCHAR* const str, const unsigned &strSize);

	/*
	@brief: This is a func to modify the coordinate by using 3 special point. If the coordinate isn't existence, it will create a new one.
	@note: Transition martix is base on the world coordinate. The convert sequence: translation->roll->ptich->yaw->zoom
	@param[in|out]: id - coordinate id. Func will renturn a new Id, when the id isn't existence in vector;
	@param[in]: p1_b - the point1 in base coordinate
	@param[in]: p2_b - the point2 in base coordinate
	@param[in]: p3_b - the point3 in base coordinate
	@param[in]: str - string of note
	@param[in]: strSize - the size of string
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned SetCoordinate(unsigned &id, const DOBOT_POSITION &p1_base, const DOBOT_POSITION &p2_base, const DOBOT_POSITION &p3_base, const TCHAR* const str, const unsigned &strSize);

	/*
	@brief: This is a func to modify the coordinate by using 3 special point. If the coordinate isn't existence, it will create a new one.
	@note: Transition martix is base on the world coordinate. The convert sequence: translation->roll->ptich->yaw->zoom
	@param[in]: p1_b - the point1 in base coordinate
	@param[in]: p2_b - the point2 in base coordinate
	@param[in]: p3_b - the point3 in base coordinate
	@param[in|out]: p1_t - the point1 in target coordinate. Func will renturn a new coordinate id to p1_t, when the id isn't existence;
	@param[in|out]: p2_t - the point2 in target coordinate. Func will renturn a new coordinate id to p2_t, when the id isn't existence;
	@param[in|out]: p3_t - the point3 in target coordinate. Func will renturn a new coordinate id to p3_t, when the id isn't existence;
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
//	unsigned SetCoordinate(const DOBOT_POSITION &p1_base, const DOBOT_POSITION &p2_base, const DOBOT_POSITION &p3_base, DOBOT_POSITION &p1_target, DOBOT_POSITION &p2_target, DOBOT_POSITION &p3_target);

	/*
	@brief: This is a func to ergodic all coordinate in vector. 
	@param[out]: coordinate
	@param[in]: reStart
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned ErgodicAllCoordinate(COORDINATE &coordinate, bool reStart = false);

	/*
	@brief: This is a func to get the id and type of the coordinate.
	@param[in]: index - index of the coordinate in vector
	@param[out]: id - id of the coordinate
	@param[out]: type - type of the coordinate
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned GetCoordianteIdAndNote(const unsigned &index, unsigned &id, TCHAR* str, unsigned &strSize);

	/*
	@brief: This is a func to get the id of the coordinate.
	@param[in]: index - index of the coordinate in vector
	@param[out]: id - id of the coordinate
	@return: if it is success, return 0; else, return a error code.
	@author: JoMar
	@date: 2016-06-12
	*/
	unsigned GetCoordianteId(const unsigned &index, unsigned &id);

private:
	/*
	@brief: the vector storing transition martixs.
	@author: JoMar
	@date: 2016-06-12
	*/
	std::vector<COORDINATE> m_vector_TM;	

	/*
	@brief: a point witch pointing the vector used in ergodicing
	@author: JoMar
	@date: 2016-06-12
	*/
	std::vector<COORDINATE>::iterator m_iter;

	/*
	@brief: This is a func to get a new ID base on the vector.
	@return: A new ID base on the martix vector.
	@author: JoMar
	@date: 2016-06-12
	*/
	inline unsigned GetNewIdOfTransitionMartix();


};

