#!/usr/bin/python3
"""0x13"""
import requests


def count_words(subreddit, word_list, word_count={}, after=""):
    ''' Gets count of occurances of word in word list '''
    if after == "":
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)

        for word in word_list:
            word_count[word.lower()] = 0
    else:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'\
               .format(subreddit, after)

    headers = {'User-Agent':
               'Python:title.parser:v0.1 (by /u/01100100011011110111)'}
    res = requests.get(url, headers=headers, allow_redirects=False)

    if (res.status_code != 200):
        return

    for title in res.json()['data']['children']:
        for word in title['data']['title'].split():
            if word.lower() in word_count.keys():
                word_count[word.lower()] += 1

    if res.json()['data']['after'] is None:
        sorted_count = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
        for item in sorted_count:
            if item[1] > 0:
                print("{}: {}".format(item[0], item[1]))
        return
    count_words(subreddit, word_list, word_count, res.json()['data']['after'])
