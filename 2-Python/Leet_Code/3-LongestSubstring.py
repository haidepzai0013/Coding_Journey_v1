def longest_substring(s: str):
       dem = 0
       t = ''
       for i in s:
           if i not in t:
               t += i
               
           else:
               if len(t) > dem:
                   dem = len(t)
               t = t[t.find(i) + 1:] + i
       return (len(t) if len(t) > dem else dem), t
           
a = input('Nhap chuoi cua ban: ')
length, st = longest_substring(a)
print("Do dai cua chuoi con dai nhat: " + str(length) + " (" + st + ")")