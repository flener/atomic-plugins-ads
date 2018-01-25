package com.ludei.ads.admob;

/**
 * Created by fabio on 24/01/18.
 */

import android.content.Context;

import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.reward.RewardItem;
import com.google.android.gms.ads.reward.RewardedVideoAd;
import com.google.android.gms.ads.reward.RewardedVideoAdListener;
import com.ludei.ads.AbstractAdRewardedVideo;
import com.ludei.ads.AdRewardedVideo;

public class RewardedVideoAdMob extends AbstractAdRewardedVideo implements RewardedVideoAdListener{

    private RewardedVideoAd zRewardedVideoAd;
    private RewardedVideoAdListener zListener;
    private String zAdUnit;

    public RewardedVideoAdMob(Context context, String adunit){

        zRewardedVideoAd = MobileAds.getRewardedVideoAdInstance(context);
        zRewardedVideoAd.setRewardedVideoAdListener(this);

        this.zAdUnit = adunit;

    }

    @Override
    public void loadAd() {
        zRewardedVideoAd.loadAd(zAdUnit, new AdRequest.Builder().addTestDevice("8F478BBA820B81CFBCF9640367497375").addTestDevice("D659633CBE66EA5904F769B6FF521404").build());
    }

    @Override
    public void show() {
        if (zRewardedVideoAd.isLoaded()) {
            zRewardedVideoAd.show();
        }
        else {
            loadAd();
        }
    }

    @Override
    public void destroy() {

    }

    @Override
    public void onRewardedVideoAdLoaded() {
        notifyOnRewardedVideoAdLoaded();
    }

    @Override
    public void onRewardedVideoAdOpened() {
        notifyOnRewardedVideoAdOpened();
    }

    @Override
    public void onRewardedVideoStarted() {
        notifyOnRewardedVideoStarted();
    }

    @Override
    public void onRewardedVideoAdClosed() {
        notifyOnRewardedVideoAdClosed();
    }

    @Override
    public void onRewarded(final com.google.android.gms.ads.reward.RewardItem rewardItem) {
        AdRewardedVideo.RewardItem rewardItem2 = new AdRewardedVideo.RewardItem(rewardItem.getType(), rewardItem.getAmount());

        notifyOnRewarded(rewardItem2);
    }

    @Override
    public void onRewardedVideoAdLeftApplication() {
        notifyOnRewardedVideoAdLeftApplication();
    }

    @Override
    public void onRewardedVideoAdFailedToLoad(int i) {
        notifyOnRewardedVideoAdFailedToLoad(i);
    }

}
