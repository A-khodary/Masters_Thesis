/*utility.h*/

void normalize(double &_X, double &_Y, double &_Z)
{
	float V = sqrt((_X*_X)+(_Y*_Y)+(_Z*_Z));
	_X = _X/V;
	_Y = _Y/V;
	_Z = _Z/V;
}

vector<double> CrossProduct(vector<double> const &a, vector<double> const &b)
{
  vector<double> r (a.size());  
  r[0] = a[1]*b[2]-a[2]*b[1];
  r[1] = a[2]*b[0]-a[0]*b[2];
  r[2] = a[0]*b[1]-a[1]*b[0];
  return r;
}

vector<double> AddVector(vector<double> const &a, vector<double> const &b)
{
  vector<double> r (a.size());  
  r[0] = a[0]+b[0];
  r[1] = a[1]+b[1];
  r[2] = a[2]+b[2];
  return r;
}

vector<double> MultiplyVector(vector<double> const &a, double val)
{
  vector<double> r (a.size());  
  r[0] = a[0]*val;
  r[1] = a[1]*val;
  r[2] = a[2]*val;
  return r;
}

bool does_file_exist(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}

const char * createOutFile(const char *fBaseName)
{
	int fNumber = 1;

	std::stringstream s;
	s << "data/"<< fNumber << fBaseName;

	std::string str = s.str();

	while(does_file_exist(str.c_str()))
	{
		fNumber++;
		std::stringstream ss;
		ss << "data/" << fNumber << fBaseName;
		str = ss.str();
	}
	return str.c_str();
}