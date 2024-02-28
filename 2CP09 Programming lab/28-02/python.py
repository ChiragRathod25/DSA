import time
import pyautogui
time.sleep(5)
count = 1
while count <= 250:
    if count%2==0:
        # pyautogui.typewrite("Abcd "+str(count)+" Efgh")
        # pyautogui.typewrite(chr(count))
        pyautogui.typewrite("Radhe-Radhe")
        pyautogui.press("enter")
        count = count+1
    else:
        # pyautogui.typewrite("Ijkl "+str(count)+" Mnop")
        pyautogui.typewrite("jay Shree Krishna")
        pyautogui.press("enter")
        count = count+1
    


