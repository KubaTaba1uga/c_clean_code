import pyautogui
from time import sleep


def write_and_press_enter(string):
    pyautogui.write(string)
    pyautogui.press("enter")


sleep(0.5)
write_and_press_enter("6")
write_and_press_enter("7")
write_and_press_enter("15")
write_and_press_enter("20")
write_and_press_enter("10")
write_and_press_enter("22")
write_and_press_enter("3")
write_and_press_enter("5")
write_and_press_enter("3 1")
write_and_press_enter("2 5")
write_and_press_enter("2 4")
write_and_press_enter("4 5")
write_and_press_enter("3 6")
