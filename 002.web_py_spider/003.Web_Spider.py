#!/usr/bin/python3
# coding=utf-8
"""Website Spider"""
import requests
import re

class TiebaSpider:
    """Tieba Spider"""
    def __init__(self):
        self.kw = input("Please input your search keyword:")
        #This is a ref url:https://tieba.baidu.com/f?ie=utf-8&kw=%E6%8B%9B%E8%81%98&fr=search
        self.base_url = "https://tieba.baidu.com/f"
        self.page_num = 1
        self.title = ""
        self.header = {"User-Agent":"Mozilla/5.0 (Windows NT 10.0;\
                Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/111.0.0.0 Safari/537.36"}    
        #some website are abandon spider,so we need to disguise our web request header. For this website can think that this request is come from a browser not a model of python . Just use chrome to type [chrome://version/]

    def parse_text(self, url, params = None):
        """发送请求，获取相应内容"""
        return #响应对象的文本信息

    def page(self, content):
        """解析每一页"""
        print("Now the Spider is obtaining Page No.{}".format(self.page_num))
        if #下页存在
            self.parse_text()
        else:
            print("Spider is now working finish, we get a total of {} pages!".format(self.page_num))

    def save_title(self):
        #保存帖子标题

    def save_img(self, url):
        #保存图片

    def start(self):
        print("Now the Spider want to work")
        content = self.parse_text(url = self.base_url, params = {'kw' : self.kw, 'ie':'utf-8', 'fr':'search'})
        self.page(content)


if __name__ == '__main__':
    spider = TiebaSpider()
    spider.start()
