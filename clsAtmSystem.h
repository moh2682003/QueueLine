#pragma once
#include "clsPerson.h"
#include <vector>
#include <fstream>
#include <string>
#include "clsString.h"
#include "clsInputValidate.h"

class clsAtmSystem : public clsPerson
{
	enum enMode {eUpDateMode = 1 , eEmptyMode = 2};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	double _AccountBalance;

	static clsAtmSystem _ConvertOneLineToRecord(string Line, string Separator = "#//#")
	{
		vector <string> vString = clsString::SplitFunction(Line, Separator);

		return clsAtmSystem(enMode::eUpDateMode, vString[0], vString[1], vString[2], vString[3], vString[4], vString[5],stod(vString[6]));
	}

	static string _ConvertRecordToOneLine(clsAtmSystem ClientRecord, string Separator = "#//#")
	{
		string Line;
		Line += ClientRecord.FirstName + Separator +
			ClientRecord.LastName + Separator +
			ClientRecord.Email + Separator +
			ClientRecord.PhoneNumber + Separator +
			ClientRecord.AccountNumber() + Separator +
			ClientRecord.PinCode + Separator +
			to_string(ClientRecord.AccountBalance);

		return Line;
	}

	static vector <clsAtmSystem> _LoadClientDateFromFile()
	{
		vector <clsAtmSystem> vAtm;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsAtmSystem ClientLine = _ConvertOneLineToRecord(Line);
				vAtm.push_back(ClientLine);
			}
			MyFile.close();
		}
		return vAtm;
	}

	static void _SaveClientRecordInFile(vector <clsAtmSystem> vAtm)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DateLine;
			for (clsAtmSystem& A : vAtm)
			{
				if (!A.IsEmpty())
				{
					DateLine = _ConvertRecordToOneLine(A);
					MyFile << DateLine << endl;

				}
			}
		}
		MyFile.close();
	}

	void _Update()
	{
		vector <clsAtmSystem> vAtm = _LoadClientDateFromFile();

		for (clsAtmSystem& C : vAtm)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C = *this;
				break;
			}
		}
		_SaveClientRecordInFile(vAtm);
	}

public :

	clsAtmSystem(enMode Mode,string FirstName, string LastName, string Email, string Phone , string AccountNumber, string PinCode,double AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	
	string getPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

	void setAccountBalance(double AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	double getAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance)) double AccountBalance;


	static clsAtmSystem Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsAtmSystem ClientLine  = _ConvertOneLineToRecord(Line);
				if (ClientLine.AccountNumber() == AccountNumber && ClientLine.PinCode == PinCode)
				{
					return ClientLine;
					break;
				}

			}
		}
		return GetEmptyObject();
		MyFile.close();
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::eEmptyMode);
	}

	static clsAtmSystem GetEmptyObject()
	{
		return clsAtmSystem(enMode::eEmptyMode, "", "", "", "", "", "",0);
	}

	enum enSaveResult {SaveSuccessfuly = 1 , SaveFailed = 2 , UnKnownError = 3};

	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::eUpDateMode:
			_Update();
			return enSaveResult::SaveSuccessfuly;
		case enMode::eEmptyMode:
			return enSaveResult::SaveFailed;
		default:
			return enSaveResult::UnKnownError;
		}
	}
	
	void WithDraw(double Amount)
	{
		AccountBalance -= Amount;
		Save();
	}

	void Deposit(double Amount)
	{
		
		AccountBalance += Amount;
		Save();
	}
	
	
};

