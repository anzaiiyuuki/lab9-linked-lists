/*
 * Course: COEN 2220 - Programming 2
 * Name: [Aida S. Mendoza Gonzalez]
 * Lab: Lab 9 - Linked Lists
 * Description: Practice - a linked list of study groups
 * Due date: [19/oct/2026]
 */

#include <iostream>
#include <string>
using namespace std;

class StudyGroupList
{
private:
    // ===== Resolve these TODOs now (Part C) =====

    // TODO (Part C): Define a Node with string groupCode, int meetingRoom, and Node *next.
    struct Node
    {
        string groupCode;
        int meetingRoom;
        Node *next;
    };
    // TODO (Part C): Declare a Node *head data member for the first node address.
    Node *head;
    // TODO (Part C): Declare an int groupCount data member for the number of stored groups.
    int groupCount;

public:
    // TODO (Part C): Write a constructor that creates an empty list and sets groupCount to zero.
        StudyGroupList()
    {
        head = nullptr; // pointer se inicia con null, empty list
        groupCount = 0;
    }

    // ===== Resolve these TODOs later (Part D) =====

    // TODO (Part D): Write addGroup. It receives a group code and room number, adds one node at the end, and updates groupCount.

    void addGroup(const string& newGroupCode, int newMeetingRoom)
    {
        Node *newNode = new Node;
        newNode->groupCode = newGroupCode;
        newNode->meetingRoom = newMeetingRoom;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        }
        else
        {
            Node *currentNode = head;

            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }

            currentNode->next = newNode;
        }

        groupCount++;
    }
    // TODO (Part D): Write displayGroups as a const member function.
        void displayGroups() const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            cout << " Study Group: " << currentNode->groupCode
                << ", Room: " << currentNode->meetingRoom << endl;

            currentNode = currentNode->next;
        }
    }
    // TODO (Part D): Write size as a const member function that returns groupCount.
        int size() const
    {
        return groupCount;
    }

    // ===== Resolve these TODOs later (Part E) =====

    // TODO (Part E): Write containsGroup as a const member function that searches by group code.
        
    bool containsGroup(const string& targetGroupCode) const
    {
        Node *currentNode = head;

        while (currentNode != nullptr)
        {
            if (currentNode->groupCode == targetGroupCode)
            {
                return true;
            }

            currentNode = currentNode->next;
        }

        return false;
    }
};

int main()
{
    cout << boolalpha;

    // TODO (Part E): Create a StudyGroupList object.
    StudyGroupList groups;

    // TODO (Part E): Add three dummy groups with different codes and room numbers.
    groups.addGroup("CHEM-105-C", 201);
    groups.addGroup("MATH-201-A", 305);
    groups.addGroup("COEN-2220-B", 110);

    // TODO (Part E): Display every stored group and print the result of size().
    groups.displayGroups();
    cout << "Total groups: " << groups.size() << endl;

    // TODO (Part E): Search for one stored group code and one missing group code.
    cout << "Contains COEN-2220-B: "
         << groups.containsGroup("COEN-2220-B") << endl;

    cout << "Contains PHYS-110-A: "
         << groups.containsGroup("PHYS-110-A") << endl;

    return 0;
}