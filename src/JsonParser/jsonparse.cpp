#include "Bass\jsonparse.h"
rapidjson::Document parser::check()
{

	std::cout << "Opening the following file: " << mRead << std::endl;
	std::ifstream mFile(mRead);
	try {
		if (!mFile) throw "File undefined condition!";
	}
	catch (const char* msg)
	{
		std::cerr << "ERROR: READING FILE : " << mRead << ". Could not find it?" << std::endl;
		std::cerr << "Usage: " << mRead << " filename" << std::endl;
	}

	rapidjson::Document document;
	rapidjson::IStreamWrapper isw(mFile);


	if (document.ParseStream(isw).HasParseError())
		std::cerr << "FAIL - JSON file Parse ERROR encountered" << std::endl;


	//Just for unit testing - I would move this to class/strut/function, use asserts, something not this.
	if (!document.HasMember("scene"))
		std::cerr << "FAIL - Not a valid scene file..." << std::endl;
	if (document["scene"]["version"].IsNull() || !document["scene"]["version"].IsString())
		std::cerr << "FAIL - Missing Version Numer!" << std::endl;
	if (document["scene"]["integrator"]["type"].IsNull() || !document["scene"]["integrator"]["type"].IsString())
		std::cerr << "FAIL - Missing Integrator in the scene file." << std::endl;

	return document;
}

int parser::getfilmw()
{
	rapidjson::Document document = check();
	return document["scene"]["sensor"]["film"]["width"].GetInt();
}

int parser::getfilmh()
{
	rapidjson::Document document = check();
	return document["scene"]["sensor"]["film"]["height"].GetInt();
}

std::string parser::filename()
{
	rapidjson::Document document = check();
	std::string file = document["scene"]["sensor"]["film"]["outputname"].GetString();
	std::string file_format = document["scene"]["sensor"]["film"]["fileFormat"].GetString();
	std::string file_name = file + "." + file_format;

	return file_name;
}

pinhole parser::getpin()
{
	rapidjson::Document document = check();

	std::cout << "Sensor Type: " << document["scene"]["sensor"]["type"].GetString() << ". Film file: "
		<< document["scene"]["sensor"]["film"]["outputname"].GetString() << "."
		<< document["scene"]["sensor"]["film"]["fileFormat"].GetString() << " of size: "
		<< document["scene"]["sensor"]["film"]["width"].GetInt() << "x" << document["scene"]["sensor"]["film"]["height"].GetInt() << std::endl;

	Eigen::Vector3d loc;
	rapidjson::Value& pos = document["scene"]["sensor"]["transform"]["position"];
	assert(pos.IsArray());
	for (rapidjson::SizeType i = 0; i < pos.Size(); i++)
	{
		loc(i) = pos[i].GetInt();
	}
	std::cout << loc << std::endl;

	Eigen::Vector3d dir;
	rapidjson::Value& view = document["scene"]["sensor"]["transform"]["viewat"];
	assert(view.IsArray());
	for (rapidjson::SizeType i = 0; i < view.Size(); i++)
	{
		dir(i) = view[i].GetInt();
	}
	std::cout << dir << std::endl;

	screen dot(document["scene"]["sensor"]["type"].GetString());
	pinhole one = dot.camToWorld(dir, loc, document["scene"]["sensor"]["transform"]["fov"].GetInt());
	
	return one;
}

std::vector<shape*> parser::getShapes()
{
	rapidjson::Document document = check();
	
	screen dot(document["scene"]["sensor"]["type"].GetString());
	rapidjson::Value& shapes = document["scene"]["shapes"];
	rapidjson::Value& ldrnm = document["scene"]["sensor"]["film"]["outputname"];

	std::string file = document["scene"]["sensor"]["film"]["outputname"].GetString();
	std::string file_format = document["scene"]["sensor"]["film"]["fileFormat"].GetString();
	std::string file_name = file + "." + file_format;

	Eigen::Vector3d cen;
	Eigen::Vector3d col(1, 1, 1);
	Eigen::Vector3d origin(0, 0, 0);
	Eigen::Vector3d dr(0, 0, 1);
	std::cout << "You have found " << shapes.Size() << " Shapes in the scene file." << std::endl;
	for (rapidjson::SizeType i = 0; i < shapes.Size(); i++) // rapidjson uses SizeType instead of size_t.
	{

		rapidjson::Value& ter = shapes[i]["position"];
		assert(ter.IsArray());
		for (rapidjson::SizeType i = 0; i < ter.Size(); i++)
		{
			cen(i) = ter[i].GetFloat();
		}
		//std::cout << cen << std::endl;

		dot.shapesToWorld(shapes[i]["type"].GetString(), cen, col, shapes[i]["radius"].GetInt());
	}

	std::vector<shape*> holder = dot.getShapes();
	
	return holder;
}


