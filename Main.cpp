
// Δομές Δεδομένων
// Θάνος Παραβάντης

#include "Flight.h"
#include <regex>

void initFlights();
void showMenu();
int readChoice();
void showFlightCodes();
int getFlightByCode(string);
string readString();
Passenger requestPassengerInformation();
bool isInteger(string);
bool isDouble(string);
void reserveSeat(Flight, int, bool);
void reserveSeat(Flight, int, Passenger, bool);
void showSingleFlightMenu();
void showMultipleFlightMenu();
void showAddFlightMenu();
void showRemoveFlightMenu();
void showFlightCancelReservationMenu();

// Αρχικοποίηση της λίστας πτήσεων του συστήματος.
LinearList<Flight> flights(100);

int main()
{
	// Εισαγωγή μερικών αρχικών πτήσεων.
	initFlights();

	// Αρχίζουμε το μενού της εφαρμογής και τρέχει για πάντα μέχρι ο χρήστης να κλείσει το πρόγραμμα.
	while (true)
	{
		showMenu();

		// Περιμένουμε από τον χρήστη μια επιλογή από το 1 έως το 5 και εμφανίζουμε το κατάλληλο μενού.

		int choice = readChoice();

		if (choice == 1)
		{
			showSingleFlightMenu();
		}
		else if (choice == 2)
		{
			showMultipleFlightMenu();
		}
		else if (choice == 3)
		{
			showAddFlightMenu();
		}
		else if (choice == 4)
		{
			showRemoveFlightMenu();
		}
		else
		{
			showFlightCancelReservationMenu();
		}

		cout << endl;
	}

	system("pause");
	return 0;
}

void initFlights()
{
	// Παραδείγματα πτήσεων: Αθήνα, Θεσσαλονίκη, Πάτρα.

	// Επειδή δεν υπάρχει πτήση από Θεσσαλονίκη σε Πάτρα,
	// ο χρήστης μπορεί να γυρίσει στην Αθήνα και να επιλέξει μια πτήση από εκεί.

	flights.insert(0, Flight("THE1",	"Athens",		"Thessaloniki",		Time(10), Time(12), 20.0, "Type1",	100,	0));
	flights.insert(1, Flight("THE2",	"Athens",		"Thessaloniki",		Time(14), Time(16), 20.0, "Type2",	1,		1));

	flights.insert(2, Flight("PAT1",	"Athens",		"Patra",			Time(16), Time(17), 10.0, "Type1",	1,		0));
	flights.insert(3, Flight("PAT2",	"Athens",		"Patra",			Time(20), Time(21), 10.0, "Type1",	1,		0));

	flights.insert(4, Flight("ATH1",	"Thessaloniki", "Athens",			Time(14), Time(16), 15.0, "Type3",	1,		0));
	flights.insert(5, Flight("ATH2",	"Thessaloniki", "Athens",			Time(18), Time(20), 15.0, "Type3",	1,		0));

	flights.insert(6, Flight("ATH3",	"Patra",		"Athens",			Time(19), Time(20), 15.0, "Type3",	1,		0));
	flights.insert(7, Flight("ATH4",	"Patra",		"Athens",			Time(22), Time(23), 15.0, "Type3",	1,		0));
}

void showMenu()
{
	cout << "Ticket System" << endl;
	cout << "Type the number of your choice." << endl << endl;

	cout << "1. Select an existing flight." << endl;
	cout << "2. Select a list of flights." << endl;
	cout << "3. Add a new flight route." << endl;
	cout << "4. Remove an existing flight route." << endl;
	cout << "5. Cancel a flight reservation." << endl;
}

int readChoice()
{
	// Έλεγχος επιλογής μενού του χρήστη, σε περίπτωση που εισάγει κάτι εκτός
	// από το 1, 2, 3, 4, 5, 6 εμφανίζεται μήνυμα λάθους και ξαναζητείται επιλογή.

	string input = "";

	cout << "> ";
	cin >> input;

	while (input.find_first_not_of("123456") != string::npos)
	{
		cout << "Invalid input, please enter a valid number." << endl;
		cout << "> ";
		cin >> input;
	}

	return stoi(input);
}

string readString()
{
	cout << "> ";
	string input;
	cin >> input;
	return input;
}

void showFlightCodes()
{
	cout << endl << "Flight routes: " << endl;
	flights.output(cout);
}

int getFlightByCode(string code)
{
	// Έλεγχος του κωδικού πτήσης που εισήγαγε ο χρήστης.
	// Θέλουμε το index της πτήσης στη λίστα flights ώστε να πάρουμε το αντικείμενο Flight.

	Flight flight;
	int flightIndex = 0;

	for (int i = 1; i <= flights.length(); i++)
	{
		// Ελέγχουμε αν ο κωδικός πτήσης αντιστοιχεί με κάποια πτήση στη λίστα.

		flights.find(i, flight);

		if (flight.getCode() == code)
		{
			flightIndex = i;
			break;
		}
	}

	// Σε περίπτωση που δεν βρεθεί στη λίστα flights η συνάρτηση επιστρέφει 0.
	return flightIndex;
}

Passenger requestPassengerInformation()
{
	// Ζητούμε τα στοιχεία του επιβάτη, θέλουμέ:
	// - Όνομα					string
	// - Επώνυμο				string
	// - Αριθμός Διαβατηρίου	int
	// - Εθνικότητα				string
	// - Διεύθυνση				string
	// - Τηλέφωνο				int

	// Με τη συνάρτηση isInteger() ελέγχουμε αν ο αριθμός διαβατηρίου και το τηλέφωνο είναι αριθμοί.

	cout << endl << "Please enter your passenger information." << endl;

	string firstname;
	cout << "First name: ";
	cin >> firstname;

	string lastname;
	cout << "Last name: ";
	cin >> lastname;

	string passportNumber;

	do
	{
		cout << "Passport number: ";
		cin >> passportNumber;
	} while (!isInteger(passportNumber));

	string nationality;
	cout << "Nationality: ";
	cin >> nationality;

	// Επειδή η διεύθυνση μπορεί να περιέχει κενά, καλούμε την getline() αφού κάνουμε cin.ignore().
	string address;
	cout << "Address: ";
	cin.ignore();
	getline(cin, address);

	string telephone;

	do
	{
		cout << "Telephone: ";
		cin >> telephone;
	} while (!isInteger(telephone));

	// Κατασκευή και επιστροφή αντικειμένου Passenger.

	Passenger passenger(firstname, lastname, stoi(passportNumber), nationality, address, stoi(telephone));
	return passenger;
}

bool isInteger(string x)
{
	// Θέλουμε string που περιέχει χαρακτήρες από 0-9 χωρίς όριο μεγέθους.
	return regex_match(x, regex("^[0-9]{1,}"));
}

bool isDouble(string x)
{
	// Θέλουμε string που περιέχει χαρακτήρες από 0-9 στο πρώτο μέλος, τελεία και το δεύτερο μέλος όπως το πρώτο.
	// Το δεκαδικό μέρος είναι προεραιτικό.
	return regex_match(x, regex("^[0-9]{1,}\.?[0-9]{1,}$"));
}

bool isTime(string x)
{
	// Θέλουμε string που περιέχει δυο χαρακτήρες από 0-9 στο πρώτο μέλος, άνω και κάτω τελεία και το δεύτερο μέλος όπως το πρώτο.
	return regex_match(x, regex("^[0-9]{2}\:[0-9]{2}$"));
}

void reserveSeat(Flight flight, int flightIndex, bool alwaysQueue = false)
{
	// Ανανέωση της λίστας επιβατών ή την ουρά του αντικειμένου flight.
	// Η παράμετρος flightIndex υποδικνύει το index του flight στη λίστα flights.
	// Η παράμετρος alwaysQueue υποδικνύει αν θέλουμε ο επιβάτης να μπαίνει πάντα στην ουρά.

	Passenger passenger = requestPassengerInformation();

	// Δεν θέλουμε να έχουμε έναν επιβάτη πολλές φορές στην ίδια πτήση.
	while (flight.hasPassenger(passenger))
	{
		cout << "Passenger has already reserved a seat on that flight." << endl;
		passenger = requestPassengerInformation();
	}

	cout << endl;

	// Καλούμε την δεύτερη έκδοση της συνάρτησης αφού έχουμε το αντικείμενο passenger.
	reserveSeat(flight, flightIndex, passenger, alwaysQueue);
}

void reserveSeat(Flight flight, int flightIndex, Passenger passenger, bool alwaysQueue = false)
{
	// Με την προϋπόθεση ότι έχουμε αντικείμενο passenger πάμε να ανανεώσουμε την λίστα επιβατών ή την ουρά του αντικειμένου flight.
	// Έχουμε δυο περιπτώσεις, αν η πτήση είναι γεμάτη τότε τοποθετούμε τον passenger σε αναμονή.
	// Αν η πτήση έχει διαθέσιμες θέσεις τότε τοποθετούμε τον passenger στη λίστα επιβατών.

	if (alwaysQueue || flight.isFull())
	{
		LinkedQueue<Passenger> queue = flight.getQueue();
		queue + passenger;
		flight.setQueue(queue);

		cout << "All seats are reserved, your position in queue is #" << queue.length() << "." << endl;
	}
	else
	{
		LinearList<Passenger> passengers = flight.getPassengers();
		passengers.insert(passenger);
		flight.setPassengers(passengers);

		cout << "Airplane seat available, you have reserved seat #" << flight.getReservations() << "." << endl;
	}

	// Επειδή έχουμε αντιγραφή της αρχικής πτήσης, ανανεώνουμε την λίστα με την τροποποιημένη πτήση.
	flights.replace(flightIndex - 1, flight);
}

void showSingleFlightMenu()
{
	// Ο χρήστης επιλέγει μια συγκεκριμένη πτήση, εισάγωντας τον κωδικό της.

	cout << endl << "Enter a single flight by it's code." << endl;

	showFlightCodes();

	string code = readString();

	// Αν ο κωδικός είναι end τελειώνουμε εδώ.
	if (code == "end") return;

	// Έλεγχος του index ώστε να εξασφαλίσουμε ότι υπάρχει η πτήση.
	int flightIndex = getFlightByCode(code);

	while (flightIndex == 0)
	{
		cout << "Invalid flight code, please try again." << endl;
		code = readString();
		
		// Εάν είναι λάθος ο κωδικός, ξανά ελέγχουμε αν τελειώνουμε εδώ.
		if (code == "end") return;

		flightIndex = getFlightByCode(code);
	}

	// Δέσμευση θέσης στη πτήση.

	Flight flight;
	flights.find(flightIndex, flight);

	reserveSeat(flight, flightIndex);
}

void showMultipleFlightMenu()
{
	// Ο χρήστης εισάγει πτήσεις κατά σειρά, εισάγωντας τον κωδικό τους.

	cout << endl << "Enter a list of flights by their code." << endl;
	cout << "Type 'end' to stop entering flight codes." << endl;

	showFlightCodes();

	LinearList<Flight> flightRoute(100); // Η λίστα με τη διαδρομή πτήσεων του χρήστη.
	LinearList<int> flightIndexes(100); // Η λίστα με τα indexes των πτήσεων στα flights.

	for (int i = 1; i <= 100; i++)
	{
		string code = readString();

		//  Αν ο κωδικός είναι end τελειώνουμε εδώ.
		if (code == "end") break;

		// Έλεγχος του index ώστε να εξασφαλίσουμε ότι υπάρχει η πτήση.
		int flightIndex = getFlightByCode(code);

		while (flightIndex == 0)
		{
			cout << "Invalid flight code, please try again." << endl;
			code = readString();

			// Εάν είναι λάθος ο κωδικός, ξανά ελέγχουμε αν τελειώνουμε εδώ.
			if (code == "end") break;

			flightIndex = getFlightByCode(code);
		}

		// Αν ο κωδικός ήταν λάθος και έχουμε κωδικό end μέσα στο προηγούμενο while, πρέπει να βγούμε και από το άρχικό loop.
		if (code == "end") break;

		Flight currentFlight;
		flights.find(getFlightByCode(code), currentFlight);

		if (i == 1)
		{
			// Εισαγωγή της πρώτης πτήσης στη διαδρομή χωρίς έλεγχο αφού δεν υπάρχει προηγούμενη.

			flightRoute.insert(i - 1, currentFlight);
			flightIndexes.insert(i - 1, flightIndex);
		}
		else
		{
			// Έλεγχος της σειράς των πτήσεων μετά την πρώτη.

			Flight previousFlight;
			flightRoute.find(i - 1, previousFlight);

			while (!previousFlight.isInOrderWith(currentFlight))
			{
				cout << "Invalid flight order, please try again." << endl;
				code = readString();

				// Όπως και πριν αν έχουμε πάλι end βγαίνουμε από το while.
				if (code == "end") break;

				flightIndex = getFlightByCode(code);

				while (flightIndex == 0)
				{
					cout << "Invalid flight code, please try again." << endl;
					code = readString();

					// Αν ο κωδικός είναι λάθος εδώ, βγαίνουμε πάλι από το while.
					if (code == "end") break;

					flightIndex = getFlightByCode(code);
				}

				// Αν ο κωδικός ήταν λάθος στο προηγούμενο while, βγαίνουμε από το αρχικό while.
				if (code == "end") break;

				// Ανανέωση της πτήσης ώστε να ελέγξουμε αν η καινούργια είναι επίσης σωστή.
				flights.find(flightIndex, currentFlight);
			}

			// Αν ο κωδικός ήταν end στο προηγούμενο while, βγαίνουμε από το αρχικό loop.
			if (code == "end") break;

			// Αν όλα πήγαν καλά κατά τον έλεγχο, εισάγουμε την πτήση στη διαδρομή.
			flightRoute.insert(i - 1, currentFlight);
			flightIndexes.insert(i - 1, flightIndex);
		}
	}

	// Αν ο χρήστης εισήγαγε πτήσης στη διαδρομή, τις εκτυπώνουμε και ζητάμε τα στοιχεία του.
	if (!flightRoute.isEmpty())
	{
		cout << endl << "Your route: " << endl;

		for (int i = 1; i <= flightRoute.length(); i++)
		{
			Flight flight;
			flightRoute.find(i, flight);

			// Θα εκτυπώσουμε και την αρχή και τον προορισμό της πρώτης πτήσης.
			if (i == 1)
				cout << flight.getOrigin() << " -> " << flight.getDestination();
			// Έπειτα μόνο τον προορισμό έπειδή η αρχή της θα είναι ο προορισμός της προηγούμενης.
			else
				cout << flight.getDestination();

			// Αν δεν είναι η τελευταία πτήση, εκτυπώνουμε βελάκια ενδιάμεσα στις πόλεις.
			if (i != flightRoute.length()) cout << " -> ";
		}

		cout << endl;
		
		// Ζητάμε την εισαγωγή των στοιχείων του επιβάτη.

		Passenger passenger = requestPassengerInformation();
		bool queueFound = false;

		for (int i = 1; i <= flightRoute.length(); i++)
		{
			Flight flight;
			flightRoute.find(i, flight);

			// Ελέγχουμε αν ο επιβάτης είναι ήδη στη πτήση ή στην ουρά αναμονής.
			while (flight.hasPassenger(passenger))
			{
				cout << "Passenger has already reserved a seat in one of those flights or is waiting in the queue." << endl;
				passenger = requestPassengerInformation();
			}

			if (i == 1) cout << endl;

			// Αν μια από τις πτήσεις είναι γεμάτη τότε θα τοποθετηθεί ο επιβάτης στις ουρές αναμονής όλων των πτήσεων της διαδρομής.

			if (flight.isFull() && !queueFound) queueFound = true;

			cout << flight.getCode() << ". ";
			
			int flightIndex;
			flightIndexes.find(i, flightIndex);

			reserveSeat(flight, flightIndex, passenger, queueFound);
		}
	}
}

void showAddFlightMenu()
{
	// Εισαγωγή νέας πτήσης στο σύστημα.
	// Για τη νέα πτήση θέλουμε:
	// - Κωδικό					string
	// - Αρχή					string
	// - Προορισμό				string
	// - Ώρα αναχώρησης			Time
	// - Ώρα άφιξης				Time
	// - Τύπος αεροπλάνου		string
	// - Τιμή εισιτηρίου		double
	// - Θέσεις αεροπλάνου		int

	cout << endl << "Enter the flight details." << endl;

	string code;
	cout << "Code (eg. TH1): ";
	cin >> code;

	// Η αρχή και ο προορισμός μπορεί να περιέχουν κενά, οπότε χρησιμοποιούμε το getline().

	string origin;
	cout << "Origin: ";
	cin.ignore();
	getline(cin, origin);

	string destination;
	cout << "Destination: ";

	getline(cin, destination);

	// Οι ώρες θέλουμε να είναι της μορφής χχ:χχ όπου χ από 0-9.
	// Χρήση της συνάρτησης isTime().

	string departureTime;

	do
	{
		cout << "Departure Time (eg. 14:20): ";
		cin >> departureTime;
	} while (!isTime(departureTime));

	string arrivalTime;

	do
	{
		cout << "Arrival Time (eg. 17:20): ";
		cin >> arrivalTime;
	} while (!isTime(arrivalTime));

	string airplaneType;
	cout << "Airplane Type: ";
	cin >> airplaneType;

	// Η τιμή θέλουμε να είναι double.
	// Χρήση της συνάρτησης isDouble().

	string ticketPrice;

	do
	{
		cout << "Ticket Price: ";
		cin >> ticketPrice;
	} while (!isDouble(ticketPrice));

	// Οι θέσεις θέλουμε να είναι int.
	// Χρήση της συνάρτησης isInteger().

	string airplaneSeats;

	do
	{
		cout << "Airplane Seats: ";
		cin >> airplaneSeats;
	} while (!isInteger(airplaneSeats));

	// Ξεχωρίζουμε τις ώρες και τα λεπτά και τις μετατρέπουμε από string σε int.
	int departureHour = stoi(string(departureTime.c_str(), departureTime.c_str() + 2));
	int departureMinute = stoi(string(departureTime.c_str() + 3, departureTime.c_str() + 5));
	int arrivalHour = stoi(string(arrivalTime.c_str(), arrivalTime.c_str() + 2));
	int arrivalMinute = stoi(string(arrivalTime.c_str() + 3, arrivalTime.c_str() + 5));

	// Μετατρέπουμε την τιμή εισιτηρίου και τις θέσεις του αεροπλάνουμε σε double και int αντίστοιχα.
	double parsedTicketPrice = atof(ticketPrice.c_str());
	int parsedAirplaneSeats = atoi(airplaneSeats.c_str());

	// Κατασκευή και εισαγωγή στα flights του νέου αντικειμένου flight.
	Flight flight(code, origin, destination, Time(departureHour, departureMinute), Time(arrivalHour, arrivalMinute), parsedTicketPrice, airplaneType, parsedAirplaneSeats, 0);
	flights.insert(flight);

	cout << endl << "Successfully created flight " << flight.getCode() << "." << endl;
}

void showRemoveFlightMenu()
{
	// Διαγραφή πτήσης με εισαγωγή κωδικού.

	showFlightCodes();

	// Δεν θέλουμε το σύστημα να έχει καμία πτήση, οπότε πρέπει να έχει τουλάχιστον δυο.

	if (flights.length() <= 1)
	{
		cout << endl << "This feature is not available, the system must have at least 2 flight routes." << endl;
	}
	else
	{
		cout << endl << "Enter the code of the flight you want to remove." << endl << endl;

		// Έλεγχος εγκυρότητας του κωδικού, αν είναι end τότε σταματάμε.

		string code = readString();

		if (code == "end") return;

		int flightIndex = getFlightByCode(code);

		while (flightIndex == 0)
		{
			cout << "Invalid flight code, please try again." << endl;
			code = readString();

			if (code == "end") return;

			flightIndex = getFlightByCode(code);
		}

		// Εύρεση και διαγραφή της πτήσης από τη λίστα flights.

		Flight flight;
		flights.find(flightIndex, flight);
		flights.remove(flightIndex, flight);

		cout << endl << "Flight " << flight.getCode() << " has been removed." << endl;
	}
}

void showFlightCancelReservationMenu()
{
	// Εκτύπωση πληροφοριών και δυνατότητα ακύρωσης πτήσεων επιβάτη.
	// Ζητάμε μόνο το όνομα, επώνυμο και τον κωδικό διαβατηρίου (ως "προσωπικό κωδικό").

	cout << endl << "Enter your full name and passport number." << endl;

	cout << "First Name: ";
	string firstname;
	cin >> firstname;

	cout << "Last Name: ";
	string lastname;
	cin >> lastname;

	cout << "Passport Number: ";
	string passportNumber;
	cin >> passportNumber;

	cout << endl;

	// Κατασκευή προσωρινού αντικειμένου για την αναζήτηση.
	Passenger passenger(firstname, lastname, stoi(passportNumber), "", "", 0);

	// Αν είναι true τότε ο επιβάτης είναι σε μια τουλάχιστον πτήση.
	bool found = false;

	// Αναζήτηση σε όλες τις πτήσεις του συστήματος.
	for (int i = 1; i <= flights.length(); i++)
	{
		Flight flight;
		flights.find(i, flight);

		bool inFlight = flight.getPassengers().search(passenger) != 0;
		bool inQueue = flight.getQueue().search(passenger);
		
		if (!found)
			found = inFlight || inQueue;

		// Εκτύπωση όλων των πτήσεων του επιβάτη.
		if (inFlight || inQueue)
		{
			if (inQueue) cout << "(QUEUED) "; // ʼν είναι στην ουρά τότε εκτυπώνουμε αυτό το πρόθεμα.

			flight.output(cout);
			cout << endl;
		}
	}

	// Αν έχουμε βρεθεί πτήσεις τότε συνεχίζουμε στην επιλογή διαγραφής τους με κωδικό πτήσης.

	if (found)
	{
		// Αν true τότε ο κωδικός που εισήγαγε ο χρήσης αντιστοιχεί σε πτήση που είναι επιβάτης ή είναι στην ουρά.
		bool validFlight = false;

		// Έλεγχος εγκυρότητας, αν ο κωδικός είναι end τότε σταματάμε.
		cout << endl << "Enter the code of the flight you want to cancel." << endl;

		while (!validFlight)
		{
			string code = readString();

			if (code == "end") break;

			int flightIndex = getFlightByCode(code);

			while (flightIndex == 0)
			{
				cout << "Invalid flight code, please try again." << endl;
				code = readString();

				if (code == "end") break;

				flightIndex = getFlightByCode(code);
			}

			if (code == "end") break;

			Flight flight;
			flights.find(flightIndex, flight);

			// Ελέγχουμε αν είναι στη λίστα επιβατών ή στην ουρά αναμονής.

			int passengerIndex = flight.getPassengers().search(passenger);
			bool inQueue = flight.getQueue().search(passenger);

			if (passengerIndex != 0 || inQueue)
			{
				// Αν είναι επιβάτης τότε τον αφαιρούμε από τη λίστα.
				if (passengerIndex)
				{
					LinearList<Passenger> passengers = flight.getPassengers();
					passengers.remove(passengerIndex, passenger);

					// Αν η νέα λίστα επιβατών είναι μικρότερη από την τωρινή τότε υπάρχουν θέσεις στο αεροπλάνο.
					if (passengers.length() <= flight.getPassengers().length())
					{
						// ʼρα ο αρχαιότερος στην ουρά μπορεί να έχει θέση, οπότε μπαίνει στη νέα λίστα επιβατών.
						LinkedQueue<Passenger> queue = flight.getQueue();
						Passenger first;
						queue - first;
						
						passengers.insert(first);
						flight.setQueue(queue);
					}

					// Ανανέσωση της λίστας επιβατών της πτήσης.
					flight.setPassengers(passengers);
				}
				// Διαφορετικά αν είναι στην ουρά τότε τον αφαιρούμε.
				else
				{
					// Κατασκευάσουμε μια νέα ουρά χωρίς τον χρήστη που αφαιρέθηκε.
					LinkedQueue<Passenger> queue = flight.getQueue();
					LinkedQueue<Passenger> newQueue;
					Passenger first;

					while (!queue.isEmpty())
					{
						queue - first;
						if (first != passenger) newQueue + first;
					}

					flight.setQueue(newQueue);
				}

				// Ανανέωση της λίστα flighs.
				flights.replace(flightIndex - 1, flight);

				cout << "Passenger removed from flight " << flight.getCode() << "." << endl;
				break;
			}
			else
			{
				cout << "Passenger hasn't selected this flight, please try again." << endl;
			}
		}
	}
	else
	{
		cout << endl << "No associated flights were found." << endl;
	}
}