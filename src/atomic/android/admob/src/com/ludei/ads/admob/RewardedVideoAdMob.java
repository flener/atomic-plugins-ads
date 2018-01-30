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
    private String zAdUnit;

    public RewardedVideoAdMob(Context context, String adunit){

        zRewardedVideoAd = MobileAds.getRewardedVideoAdInstance(context);

        /*
            As zRewardedVideoAd is a singleton, the existence of 2 or more RewardedVideoAdMob will cause
            all of the requests to zRewardedVideoAd requests being listened by just the last RewardedVideoAdMob created.
            That is why we choose for our project to do the re-mapping of the events on AdServiceBridge.
         */
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
