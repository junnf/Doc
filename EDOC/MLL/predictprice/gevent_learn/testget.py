#!/usr/bin/env python
import time
import gevent
import requests
import gevent.monkey

#  gevent.monkey.patch_socket()

tic = lambda: 'at %1.1f seconds' % (time.time() - start)

def get_url(id,url="http://www.fiberhome.com"):
    print("id {}".format(id))
    print("start: %s" % tic())
    requests.get(url)
    print("end: %s" % tic())

def sync():
    for i in range(1,50):
        get_url(i)

def async():
    threads = [gevent.spawn(get_url, i) for i in xrange(50)]
    gevent.joinall(threads)

start =time.time()
sync()
start =time.time()
async()

