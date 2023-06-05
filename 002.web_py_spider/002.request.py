# coding=utf-8
import requests
url = "https://www.zhihu.com/"
r = requests.get(url,)
r.encoding = 'utf-8'
print(r.text)

r1 = requests.get(url, params = {'key1' : 'question', 'key2':'291980869', 'key3':'answer', 'key4':'2013251011'})
print(r1.url)
r2 = requests.post(url, data = {'key' : 'value'})
print(r2.url)
