# PasswordGeneratorAndClear
Simple password generator that automatically copies a randomly generated password to the clipboard without printing it to the console. The password can then be pasted to the password field of a new account form. After pasting the password a user can hit the enter key in the console and the password is wiped from the clipboard memory and application memory. 

Other anti-forensics concerns to consider for preventing password recovery include clearing the memory of the application where the password was pasted. (e.g. a web browser). Note passwords should never be saved in the web browser's password storage if you do not want the password recovered.
