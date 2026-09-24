#include "ClientManger.h"
#include <string>
#include "FilesHelper.h"
#include "FileManager.h"
#include "Screens.h"


void ClientManger::printClientMenu(){
	cout <<"===============CLIENT MENU=================\n\n";
	cout << "1.Deposit.\n";
	cout << "2.Withdraw.\n";
	cout << "3.TransferTo.\n";
	cout << "4.CheckBalance.\n";
	cout << "5.UpdatePassword.\n";
	cout << "6.Logout.\n\n";	
}
void ClientManger::updatePassword(Person* person){
	cout << "==============Update Password===============\n";

	for (int i = 0; i < FilesHelper::Clients.size();i++) {
		if (person->getId() == FilesHelper::Clients[i].getId()) {
			string password;
			cout << "Enter your password :";
			cin.ignore();getline(cin, password);
			while (password != person->getPassword()) {
				cout << "Incorrect password ,Please try again .\n";
				cout << "Enter your password :";
				getline(cin, password);
			}
			
			cout << "Enter the new password :";
			getline(cin, password);
			FilesHelper::Clients[i].setPassword(password);
			cout << "Password updated successfully.\n";
			FileManager fm;
			fm.updateClient();
			return;
		}
	}
	cout << "No client found with this ID.\n";
	ClientManger::printClientMenu();
	return;
}
Client* ClientManger::login(int id, string password){
		if (id > 0 && id <= FilesHelper::Clients.size() && password == FilesHelper::Clients[id-1].getPassword()) {
		 	cout << "Login Successfully.\n";
			cout << "Welcome ," << FilesHelper::Clients[id-1].getName() << "\n";
			Client* client = new Client(FilesHelper::Clients[id-1]);
			return client;
		}
	
	return nullptr;
}
bool ClientManger::clientOptions(Client* client){
	ClientManger::printClientMenu();
	cout << "Enter your choice:";
	int choice; cin >> choice;
	switch (choice) {
	case 1: {
		cout << "================Deposit=====================\n";
		cout << "Enter the amount:";
		double amount;cin >> amount;
		client->deposit(amount);
		break;
	}
	case 2: {
		cout << "================Withdraw====================\n";
		cout << "Enter the amount:";
		double amount;cin >> amount;
		client->withdraw(amount);
		break;
	}
	case 3: {
		cout << "================TransferTo==================\n";
		cout << "Enter recipient client ID :";
		int id; cin >> id;
		if (id > 0 && id <= FilesHelper::Clients.size()) {
			cout << "Enter the amount:";
			double amount;cin >> amount;
			client->transferTo(amount, FilesHelper::Clients[id - 1]);
		}
		else {
			cout << "No client found with this ID.";
		}
		break;
	}
	case 4: {
		client->checkBalance();
		break;
	}
	case 5: {
		ClientManger::updatePassword(client);
		break;
	}
	case 6: {
		return false;
	}
	default: {
		cout << "Invalid choice.\n";
		return false;
	}
	}
	return true;
}