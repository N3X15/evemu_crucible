#include "EVECommonPCH.h"
#include "database/DBInsertBuilder.h"


DBInsertBuilder::DBInsertBuilder(const char* tablename)
{
	tableName=tablename;
}


DBInsertBuilder::~DBInsertBuilder(void)
{
}

std::string DBInsertBuilder::AsString(void)
{	
	std::stringstream values;
	std::stringstream columns;
	ValueMap::const_iterator end = mMap.end();
	bool isFirst=true;
	for (ValueMap::const_iterator it = mMap.begin(); it != end; ++it) {
		if(!isFirst) {
			values << ", ";
			columns << ", ";
		}
		columns << it->first;
		values << it->second;
		isFirst=false;
	}

	std::string ret("");
	sprintf(ret,"INSERT INTO %s (%s) VALUES (%s);",tableName,columns.str().c_str(),values.str().c_str());
	return ret;
}

void DBInsertBuilder::_AddColumn(const char *column,std::string data) {
	mMap.insert(std::pair<std::string,std::string>(
		std::string(column),
		data
	));
}

void DBInsertBuilder::AddColumn(const char *column,const char *data) {
	std::string esc;
	sprintf(esc,"'%s'",data);
	_AddColumn(column,esc);
}

void DBInsertBuilder::AddColumn(const char *column,std::string data) {
	std::string esc;
	sprintf(esc,"'%s'",data);
	_AddColumn(column,esc);
}

void DBInsertBuilder::AddColumn(const char *column,int data) {
	std::stringstream str;

	str << data;

	_AddColumn(column,str.str());
}

void DBInsertBuilder::AddColumn(const char *column,uint32 data) {
	std::stringstream str;

	str << data;

	_AddColumn(column,str.str());
}

void DBInsertBuilder::AddColumn(const char *column,uint64 data) {
	std::stringstream str;

	str << data;

	_AddColumn(column,str.str());
}

void DBInsertBuilder::AddColumn(const char *column,int64 data) {
	std::stringstream str;

	str << data;

	_AddColumn(column,str.str());
}

void DBInsertBuilder::AddColumn(const char *column,double data) {
	std::stringstream str;

	str << data;

	_AddColumn(column,str.str());
}