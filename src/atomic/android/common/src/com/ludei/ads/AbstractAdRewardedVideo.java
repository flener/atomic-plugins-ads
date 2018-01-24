package com.ludei.ads;

/**
 * Created by fabio on 24/01/18.
 */

public abstract class AbstractAdRewardedVideo implements AdRewardedVideo {

    private RewardedVideoListener zListener;


    @Override
    public void setListener(RewardedVideoListener listener) {
        zListener = listener;
    }

    public void notifyOnRewardedVideoAdLoaded() {
        if(zListener != null){
            zListener.onAdLoaded(this);
        }
    }

    public void notifyOnRewardedVideoAdOpened() {
        if(zListener != null){
            zListener.onAdOpened(this);
        }
    }

    public void notifyOnRewardedVideoStarted() {
        if(zListener != null){
            zListener.onAdStarted(this);
        }
    }

    public void notifyOnRewardedVideoAdClosed() {
        if(zListener != null){
            zListener.onAdClosed(this);
        }
    }

    public void notifyOnRewarded(RewardItem rewardItem) {
        if(zListener != null){
            zListener.onRewarded(this, rewardItem);
        }
    }

    public void notifyOnRewardedVideoAdLeftApplication() {
        if(zListener != null){
            zListener.onAdLeftApplication(this);
        }
    }

    public void notifyOnRewardedVideoAdFailedToLoad(int i) {
        if(zListener != null){
            zListener.onAdFailedToLoad(this, i);
        }
    }

}
