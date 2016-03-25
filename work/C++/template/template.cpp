#include <iostream>
#include <string>
using namespace std;
#define GC2235_SENSOR_ID 0x11
#define OV5648_SENSOR_ID 0x12
typedef enum
{   
	EType_RAW =   0, 
	EType_YUV,      
}   EType;
template <EType _sensor_type, int _sensor_id> 
class SensorInfo
{
	public:
		typedef SensorInfo<_sensor_type, _sensor_id>    SensorInfo_T;
		static  SensorInfo_T* getInstance() { static SensorInfo_T inst;return &inst; }
		virtual EType           GetType() const { return _sensor_type; }
		virtual int GetID()   const { return _sensor_id;   } 
		string GetString()
		{
			return GetType()?"RAW Sensor":"YUV Sensor";
		}
};

#if 0
template <> string SensorInfo<EType_RAW,GC2235_SENSOR_ID>::GetString()
{
	return "RAW Sensor";
}

template <> string SensorInfo<EType_YUV,OV5648_SENSOR_ID>::GetString()
{
	return "YUV Sensor";
}
#endif

int main(int argc, char **argv)
{
	SensorInfo<EType_RAW,GC2235_SENSOR_ID>* gc2235 = SensorInfo<EType_RAW,GC2235_SENSOR_ID>::getInstance();
	cout << "Sensor info:"<<gc2235->GetString()<<endl<<"Sensor ID:"<<gc2235->GetID()<<endl;

	SensorInfo<EType_YUV,OV5648_SENSOR_ID>* ov5648p = SensorInfo<EType_YUV,OV5648_SENSOR_ID>::getInstance();
	cout << "Sensor info:"<<ov5648p->GetString()<<endl<<"Sensor ID:"<<ov5648p->GetID()<<endl;

	SensorInfo<EType_YUV,OV5648_SENSOR_ID> ov5648;
	cout << "Sensor info:"<<ov5648.GetString()<<endl<<"Sensor ID:"<<ov5648.GetID()<<endl;

	return 0;
}
