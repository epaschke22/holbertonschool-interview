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
    try:
        res = requests.get(url, headers=header, allow_redirects=False).json()
        for post in res['data']['children']:
            for key in wordcount:
                if key.lower() in post['data']['title']:
                    wordcount[key.lower()] += 1
    except ValueError:
        return None

    after = res['data']['after']
    if after is None:
        for key in sorted(wordcount.items(), key=lambda x: x[1], reverse=True):
            if key[1] > 0:
                print("{}: {}".format(key[0], key[1]))
        return
    count_words(subreddit, word_list, wordcount, after)
