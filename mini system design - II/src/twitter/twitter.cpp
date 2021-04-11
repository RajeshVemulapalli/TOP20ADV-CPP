#include <cstdlib>
#include <ctime>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Tweet {
private:
	string text;
	int ts;
public:
	Tweet(string text, int ts) {
		this->text = text;
		this->ts = ts;
	}
	const string& getText() const {
		return text;
	}

	void setText(const string &text) {
		this->text = text;
	}

	int getTs() const {
		return ts;
	}

	void setTs(int ts) {
		this->ts = ts;
	}
};

struct Comparator {
	bool operator()(Tweet &t1, Tweet &t2) {
		return t2.getTs() < t1.getTs();
	}
};
class MiniTwitter {
	unordered_map<string, vector<Tweet>> tweets;
	unordered_map<string, unordered_set<string>> followers;
	unordered_map<string, unordered_set<string>> followees;
public:
	void postTweet(string user_id, string tweet_text, int ts) {
		if (tweets.find(user_id) == tweets.end())
			tweets[user_id] = vector<Tweet>();
		tweets[user_id].push_back(Tweet(tweet_text, ts));
	}
	void follow(string follower_id, string followee_id) {
		if (followers.find(followee_id) == followers.end())
			followers[followee_id] = unordered_set<string>();
		followers[followee_id].insert(follower_id);

		if (followees.find(follower_id) == followees.end())
			followees[follower_id] = unordered_set<string>();
		followees[follower_id].insert(followee_id);
	}
	void unfollow(string follower_id, string followee_id) {
		if (followers.find(followee_id) != followers.end())
			followers[followee_id].erase(follower_id);
		if (followees.find(follower_id) != followees.end())
			followees[follower_id].erase(followee_id);
	}
	vector<Tweet> timeline(string user_id) {
		if (tweets.find(user_id) == tweets.end())
			return {};
		vector<Tweet> user_tweets = tweets[user_id];
		int n = user_tweets.size();
		int ntweets = min(10, n);
		vector<Tweet> res;
		for (int i = 0; i < ntweets; ++i) {
			res.push_back(user_tweets[n - 1 - i]);
		}
		return res;
	}
	vector<Tweet> newsfeed(string user_id) {
		//collect the feed of given user
		vector<Tweet> feed = timeline(user_id);

		//collect the feed for all the followees of given user
		unordered_set<string> user_followees = followees[user_id];
		for (auto &followee : user_followees) {
			vector<Tweet> tmp = timeline(followee);
			for (auto &t : tmp)
				feed.push_back(t);
		}

		sort(feed.begin(), feed.end(), Comparator());

		//collect top10 news feed tweets
		int n = feed.size();
		int ntweets = min(10, n);
		vector<Tweet> res;
		for (int i = 0; i < ntweets; ++i) {
			res.push_back(feed[i]);
		}
		return res;

	}
};

int main(int argc, char *argv[]) {
	MiniTwitter twitter;
	int nusers = 5;
	for (int ts = 0; ts < 100; ++ts) {
		int rid = rand() % nusers;
		twitter.postTweet("user" + to_string(rid),
				"tweet" + to_string(rid) + "_" + to_string(ts), ts);
	}
	for (int i = 0; i < nusers; ++i) {
		vector<Tweet> res = twitter.timeline("user" + to_string(i));
		cout << "user" + to_string(i) + ":";
		for (auto &t : res)
			cout << t.getText()<<" ";
		cout << endl;
	}
	twitter.follow("user0", "user1");
	twitter.follow("user1", "user2");
	twitter.follow("user0", "user2");
	vector<Tweet> res = twitter.newsfeed("user0");
	for (auto &t : res)
		cout << t.getText() << " ";

}
