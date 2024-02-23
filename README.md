# Hostel Management System

This Hostel Management System is a C++ application with MySQL integration designed to streamline the management of a hostel. The system includes functionalities for both wardens (administrators) and students.

## Features

### For Warden (Admin)

1. **View All Student Details**
   - Retrieve and display a comprehensive list of all students in the hostel.

2. **Add Student**
   - Add a new student to the hostel database.
   - Required details: Enrollment Number, Name, Room Number, Roommate, Contact Number, Parent Contact.

3. **Delete Student**
   - Remove a student from the hostel database using their Enrollment Number.

4. **Update Student Details**
   - Modify information about a particular student.
   - Choose to update Enrollment Number, Name, Room Number, Roommate, Contact Number, or Parent Contact.

5. **Get Student Details**
   - Retrieve and display detailed information for a specific student using their Enrollment Number.

### For Students

1. **Get Details**
   - View personal details including Enrollment Number, Name, Room Number, Roommate, Contact Number, and Parent Contact.

2. **Request Outpass**
   - Submit a request for an outpass.
   - Tracks whether the outpass has been approved.

3. **Cleaning Request**
   - Request room cleaning services.
   - Tracks the status of the cleaning request.

4. **Roommate Details (To be implemented)**
   - Future feature: View details about roommates.

## Getting Started

1. **Clone the repository:**

    ```bash
    git clone https://github.com/RisheekShukla/HostelMgmtSystem.git
    ```

2. **Set up MySQL Database:**
   - Ensure you have a MySQL server installed.
   - Create a database named `extra`.
   - Import the SQL script (`database.sql`) to set up the required table structure.

3. **Compile and Run:**
   - Open the project in your C++ IDE (DevC++, Code::Blocks, etc.).
   - Build and run the project.

## Dependencies

- C++ compiler (supporting C++11)
- MySQL server
- MySQL Connector/C++ library

## Contributing

Contributions are welcome! If you have any suggestions, improvements, or feature ideas, feel free to open an issue or submit a pull request.
