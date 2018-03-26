#!/usr/bin/env python

import requests
import gevent
from lxml import etree
from info import district_data

#  import gevent.monkey
#  gevent.monkey.patch_socket()

class HouseData():
    def __init__(self):
        self.datasets = []
        self._get = lambda data, headers : requests.post("http://m.cityhouse.cn/wuhan/hanew/ajaxmorelist.html?type=new",
                headers = headers,
                data = data)
        pass

    def area(self, area):
        return district_data[area]

    def handle_price(self, text):
        _temp = text.strip(u'均价').split(',')
        return (_temp[0] + _temp[1])

    def handle_district(self, text):
        _temp = text.split(u" ")[0].strip()
        return district_data[_temp]


    def info_filter(self, text):
        html = etree.HTML(text)
        for x in html.xpath('//li/a/div[@class="right right_bottom"]/span[@class="price"]'):
            pass

        for y in html.xpath('//li'):



    def scratch(self, pages=100):
        headers = {
                   'Content-Length': '326',
                   'Accept-Language': 'en-US,en;q=0.5',
                   'X-Requested-With': 'XMLHttpRequest',
                   'Connection': 'keep-alive',
                   'Accept': 'text/html, */*; q=0.01',
                   'User-Agent': 'Mozilla/5.0 (X11; Linux x86_64; rv:52.0) Gecko/20100101 Firefox/52.0',
                   'Host': 'm.cityhouse.cn',
                   'Referer': 'http://m.cityhouse.cn/wuhan/ha/',

                   'Cookie': '_ga=GA1.2.615489782.1521646073; __auc=014a1040162492c7751511d13c7; \
                   UM_distinctid=162492c7aef439-0efaedf790a9058-38694646-100200-162492c7af0198;  \
                   _gid=GA1.2.1363184392.1521956840; cityre=a495f189ec3766d2e462465b47d54d47; \
                   CNZZDATA1262058535=2113925628-1521964319-http%253A%252F%252Fm.cityhouse.cn%252F%7C1521964319; \
                   _gat=1; __asc=b49d1d0d1625c2e33c1f6713307',

                   'Content-Type': 'application/x-www-form-urlencoded; charset=UTF-8'
                   }

        data = {'p[ob]': '0',
                'p[bz]': '',
                'p[proptype]': '',
                'p[all]': '',
                'p[gps]': '',
                'p[hadistance]': '',
                'p[keywords]': '',
                'p[streetcode]': '',
                'p[town]': '',
                'p[area_code]': '',
                'p[bz_choice]': '',
                'p[stationcode]': '',
                'p[urbanid]': '',
                'p[district]': '',
                'p[bldgcode]': '',
                'p[page]': '',
                'p[haclcode]': '',
                'p[p2]': '0',
                'p[pagesize]': '20',
                'p[p1]': '0',
                'p[hacode]': ''}


        for i in range(pages):
            headers["p[page]"] = str(i+1)
            print data
            self.info_filter(self._get(data, headers).text)

house = HouseData()
house.scratch()

if __name__ == "__main__":
    pass
