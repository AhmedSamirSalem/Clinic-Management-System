# Clinic System

Clinic System is a user-friendly software designed to manage a clinic with two distinct modes: Admin and User. In the Admin mode, administrators can add and edit patient data, reserve slots with doctors, and cancel reservations. In User mode, users can view patient records and today's reservations.

## Admin Mode

### Authentication
- The system requires a password to enter Admin mode, and the default password is 1234.
- If the password is entered incorrectly three consecutive times, the system will close.

### Features
1. **Add New Patient Record:**
   - Admins can add new patient records by providing basic information such as name, age, gender, and a unique patient ID.
   - The system rejects entries with duplicate patient IDs.

2. **Edit Patient Record:**
   - Admins can edit patient records by entering the patient's unique ID.
   - If the ID exists, the system allows the user to edit the patient information; otherwise, it displays an incorrect ID message.

3. **Reserve a Slot with the Doctor:**
   - There are five default available slots: 2pm to 2:30pm, 2:30pm to 3pm, 3pm to 3:30pm, 4pm to 4:30pm, and 4:30pm to 5pm.
   - Admins can reserve a slot by entering the patient's ID and the desired slot time.
   - Once a slot is reserved, it won't appear in the available slots window for the next patient.

4. **Cancel Reservation:**
   - Admins can cancel a reservation by entering the patient's ID.
   - The canceled reservation will become available again in the slots window.

## User Mode

In User mode, no password is required, and users can perform the following actions:

1. **View Patient Record:**
   - Users can view a patient's basic information by entering the patient's unique ID.

2. **View Today's Reservations:**
   - Users can view all reservations for the current day, with patient IDs attached to each reservation slot.

---
