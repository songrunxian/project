# coding=utf-8
"""urllib的使用"""
import urllib.request

response = urllib.request.urlopen("https://baijiahao.baidu.com/s?id=1767690854710413643")
content = response.read().decode("utf-8")
fo = open("./xinwen.html", "w", encoding="utf-8")
print(content, file = fo)
fo.close()
#open xinwen.html

#响应头信息
print(response.headers)
#响应码
print(response.status)
