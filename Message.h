#pragma once
#include <string>

class Message
{
private:
	std::string mStr_1{ "" };
	/*ParamType_0 mParam_0{};
	ParamType_1 mParam_1{};*/
	union
	{
		const void* mParameter_0 = nullptr;
		char mParameterRawData_0[256];
	};
	union
	{
		const void* mParameter_1 = nullptr;
		char mParameterRawData_1[256];

	};

public:
	

	Message()
	{
	
	}
	

	void SetIdentifier(std::string inStr_1)
	{
		mStr_1 = inStr_1;
	
	}

	template<class ParamType_0>
	void SetParam_0(const ParamType_0* inParam_0)
	{
		mParameter_0 = inParam_0;
	    
	}

	template<class ParamType_1>
	void SetParam_1(const ParamType_1* inParam_1)
	{
		mParameter_1 = inParam_1;
	
	}

	template<class ParamType_0>
	ParamType_0* GetParam_0()
	{
		return (ParamType_0*) mParameter_0;
	
	}

	template<class ParamType_1>
	ParamType_1* GetParam_1()
	{
		return (ParamType_1*)mParameter_1;
	
	}

	template <class ParamType_0>
	void SetValue_0(const ParamType_0& inParamValue_0)
	{
		const void* P_0 = (const void*)mParameterRawData_0;
		*(ParamType_0*)P_0=inParamValue_0;
	    
	}

	template <class ParamType_1>
	void SetValue_1(const ParamType_1& inParamValue_1)
	{
		const void* P_1 = (const void*)mParameterRawData_1;
		*(ParamType_1*)P_1 = inParamValue_1;

	}

	template<class ParamType_0>
	ParamType_0 GetValue_0()
	{
		const void* P_0 = (const void*)mParameterRawData_0;
		return *(ParamType_0*)P_0;
	
	}

	template<class ParamType_1>
	ParamType_1 GetValue_1()
	{
		const void* P_1 = (const void*)mParameterRawData_1;
		return *(ParamType_1*)P_1;

	}

	std::string GetIdentifier()
	{
		//OutputDebugStringA(mStr_1.c_str());
		
		return mStr_1;

	
	}
	
	
	


	
	


	


};