#!/usr/bin/python3
"""0x13"""
import requests


def count_words(subreddit, word_list=[], wordcount={}, after=""):
    """returns all hot items of a subreddit recursively"""
    if after == "":
        url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
        for word in word_list:
            wordcount[word] = 0
    else:
        url = 'https://www.reddit.com/r/{}/hot.json?after={}'\
               .format(subreddit, after)

    header = {'User-Agent': 'Python:sub.counter:v0.1 (by /u/willy)'}
    res = requests.get(url, headers=header, allow_redirects=False)
    if (res.status_code != 200):
        return
    for post in res.json()['data']['children']:
        for word in post['data']['title'].split():
            if word.lower() in wordcount.keys():
                wordcount[word.lower()] += 1

    after = res.json()['data']['after']
    if after is None:
        for key in sorted(wordcount.items(), key=lambda x: x[1], reverse=True):
            if key[1] > 0:
                print("{}: {}".format(key[0], key[1]))
        return
    count_words(subreddit, word_list, wordcount, after)
