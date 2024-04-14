class Solution:
    def findLatestTime(self, tango: str) -> str:
        wacky_list = list(tango)
        if wacky_list[0] == "?":
            wacky_list[0] = "1" if wacky_list[1] == "?" or int(wacky_list[1]) <= 1 else "0"
        if wacky_list[1] == "?":
            wacky_list[1] = "1" if wacky_list[0] == "1" else "9"
        if wacky_list[3] == "?":
            wacky_list[3] = "5"
        if wacky_list[4] == "?":
            wacky_list[4] = "9"
        return "".join(wacky_list)

        