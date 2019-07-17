# About vacation_backlog programm
It is console application to re-calculate vacational balance of employees

# How it works

When user click on the **Vacation_1.exe**, they see simpleapplication dialog.
![1](https://user-images.githubusercontent.com/38506033/61373179-ce8c1a00-a8a1-11e9-9f0c-5843a9b27318.JPG)

By default programm is looking for a .txt file in currently folder. Or user can enter the file name from the command line or inside the dialog window.
The input file should be in format: *employee number*, *hiring date*.
Be the SRS this information can be gined from 1C-Accounting.

![2](https://user-images.githubusercontent.com/38506033/61373184-d0ee7400-a8a1-11e9-9898-f35aa43f579d.JPG)

Then the programm asks user about new date for recalculate vacation balance.
In result will be create txt-file *result.txt* in format *employee #*, *Hiring date*, *Last working period*, *Vacational balance*.
This format allows to import information in Excel file or in to 1C.


