#!/usr/bin/python3
"""0x13"""
import requests


def count_words(subreddit, word_list=[]):
    """returns all hot items of a subreddit recursively"""
    if len(word_list) == 0:
        return
    wordcount = {}
    for word in word_list:
        wordcount[word.lower()] = 0
    result = recursive(subreddit, wordcount, "NULL")
    if result is not None:
        for key in sorted(result):
            if result[key] > 0:
                print("{}: {}".format(key, result[key]))


def recursive(subreddit, wordcountdict, after="NULL"):
    """recursive function"""
    url = 'https://www.reddit.com/r/{}/hot.json'.format(subreddit)
    header = {'User-Agent': 'Python:sub.counter:v0.1 (by /u/willy)'}
    param = {'after': after}
    try:
        res = requests.get(url, headers=header, params=param,
                           allow_redirects=False).json()
        for post in res['data']['children']:
            for key in wordcountdict:
                if key in post['data']['title']:
                    wordcountdict[key] += 1
    except ValueError:
        return None
    after = res['data']['after']
    if after not in [None, 'None', 'NULL']:
        return recursive(subreddit, wordcountdict, after)
    return wordcountdict
