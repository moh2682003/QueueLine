#pragma once
#include <queue> 
#include <stack>
#include "clsDateLibrary.h"
#include <iostream>


using namespace std;

class clsQueueLine
{
	string _Prefix = "";
	int _TotalTicket = 0;
	int _AverageTime = 0;

	class _clsTicket
	{
		int _Number = 0;
		string _Prefix = "";
		string _TicketTime;
		int _WaitingClients = 0;
		int _AverageTime = 0;
		int _ExpectedServerTime = 0;

	public:
		_clsTicket(string prefix, int Number, int WaitingClient, int ServerTime)
		{
			_Prefix = prefix;
			_Number = Number;
			_WaitingClients = WaitingClient;
			_TicketTime = clsDateLibrary::GetSystemDateTimeString();
			_ExpectedServerTime = ServerTime;
		}

		string Prefix()
		{
			return _Prefix;
		}

		int Number()
		{
			return _Number;
		}

		int WaitingClient()
		{
			return _WaitingClients;
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		string FullNumber()
		{
			return _Prefix + (to_string(_Number));
		}

		int ExpectedServeTime()
		{
			return _WaitingClients * _AverageTime;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";


		}
	};
	

public :

	queue <_clsTicket> QueueLine;

	clsQueueLine(string Prefix, int AverageServerTime)
	{
		_Prefix = Prefix;
		_AverageTime = AverageServerTime;
		_TotalTicket = 0;
	}

	void IssueTicket()
	{
		_TotalTicket++;
		_clsTicket Ticket(_Prefix, _TotalTicket, WaitingClient(), _AverageTime);
		QueueLine.push(Ticket);

	}

	int WaitingClient()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Clients Left.";
		else
			return QueueLine.front().FullNumber();
	}

	bool ServerNextClient()
	{
		if (QueueLine.empty())
			return false;

		QueueLine.pop();
		return true;
	}

	int ServedClient()
	{
		return _TotalTicket * WaitingClient();
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTicket;
		cout << "\n\t\t\t    Served Clients  = " << ServedClient();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClient();
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}

	void PrintTicketsLineRTL()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <_clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			_clsTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.FullNumber() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";

	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <_clsTicket> TempQueueLine = QueueLine;
		stack <_clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			_clsTicket Ticket = TempStackLine.top();

			cout << " " << Ticket.FullNumber() << " --> ";

			TempStackLine.pop();
		}
		cout << "\n";
	}


	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <_clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}

	}


};

