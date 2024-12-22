#include <iostream>
#include <string>

// base class for single inheritance...
class Employee {
    protected:
        std::string name;
        int employeeId;

    public:
        // initialization list...
        Employee(const std::string &empName, int empId) : name(empName), employeeId(empId) {
            std::cout << __FUNCTION__ << std::endl;
        }

        void display() const {

            std::cout << "Employee: " << name << ", ID: " << employeeId << std::endl;
        }
};

// derived class for single inheritance...
class Developer : public Employee {
    private:
        std::string programmingLanguage;

    public:
        Developer(const std::string &empName, int empId, const std::string &lang) : Employee(empName, empId), programmingLanguage(lang) {

        }

        void show() const {

            display();

            std::cout << "Specialization: Developer, ProgrammingLanguage: " << programmingLanguage << std::endl;

        }
};

// base class for multilevel inheritance...
class HRManager : public Employee {
    public:
        HRManager(const std::string &empName, int empId) : Employee(empName, empId) {
            std::cout << __FUNCTION__ << std::endl;
        }

        void handleHRDuties() const {

            std::cout << "HR Manager handling human resources duties..." << std::endl;
        }
};

// derived class for multilevel inheritance...
class HRDirector : public HRManager {
    public:
        HRDirector(const std::string &empName, int empId) : HRManager(empName, empId) {
            std::cout << __FUNCTION__ << std::endl;
        }

        void manageHRDepartment() const {

            std::cout << "HR Director managing the HR department..." << std::endl;
        }
};

// base class for multiple inheritance...
class ProjectManager {
    protected:
        std::string projectManaged;

    public:
        ProjectManager(const std::string &project) : projectManaged(project) {

        }

        void manageProject() const {

            std::cout << "Project Manager managing project: " << projectManaged << std::endl;
        }
};

class TeamLead {
    protected:
        int teamSize;

    public:
        TeamLead(int size) : teamSize(size) {

        }

        void leadTeam() const {

            std::cout << "Team Lead leading a team of " << teamSize << " members." << std::endl;
        }
};

// derived class for multiple inheritance...
class TechLead : public Employee, public ProjectManager, public TeamLead {
    public:
        TechLead(const std::string &empName, int empId, const std::string &project, int teamSize) : Employee(empName, empId), ProjectManager(project), TeamLead(teamSize) {

        }

        void displayInfo() const {

            display();
            manageProject();
            leadTeam();
        }
};

// base class for hierarchical inheritance...
class Executive : public Employee {
    public:
    Executive(const std::string &empName, int empId) : Employee(empName, empId) {

    }

    void manageExeDecision() const {

        std::cout << "Executive making executive decisions..." << std::endl;
    }
};

// derived clasd for hierarchical inheritance...
class Ceo : public Executive {
    public:
    Ceo(const std::string &empName, int empId) : Executive(empName, empId) {

    }

    void leadCompany() const {

        manageExeDecision();
        std::cout << "CEO leading the company..." << std::endl;
    }
};




int main() {

    // single inheritance...
    // Developer dev("Ramu Kaka", 101, "C++");
    // dev.show();

    // multiple inheritance...
    // TechLead techLead("Anna Dev", 202, "Project X", 5);
    // techLead.displayInfo();

    // multilevel inheritance...
    // HRDirector hrDirector("Lucy Madam", 303);
    // hrDirector.handleHRDuties();
    // hrDirector.manageHRDepartment();

    // hierarchical inheritance...
    Ceo ceo("Devi Lal", 404);
    ceo.leadCompany();



    return 0;
}