package com.ludei.ads;

/**
 * Created by fabio on 24/01/18.
 */

public interface AdRewardedVideo {
    void setListener(RewardedVideoListener listener);

    void loadAd();

    void show();

    void destroy();

    public interface RewardedVideoListener {

        public void onAdLoaded(AdRewardedVideo adRewardedVideo);

        public void onAdOpened(AdRewardedVideo adRewardedVideo);

        public void onAdStarted(AdRewardedVideo adRewardedVideo);

        public void onAdClosed(AdRewardedVideo adRewardedVideo);

        public void onRewarded(AdRewardedVideo adRewardedVideo, RewardItem rewardItem);

        public void onAdLeftApplication(AdRewardedVideo adRewardedVideo);

        public void onAdFailedToLoad(AdRewardedVideo adRewardedVideo, int i);
    }

    public static class RewardItem {
        public RewardItem(String type, int amount){
            zType = type;
            zAmount = amount;
        }
        protected String zType;
        protected int zAmount;

        public String getType(){
            return zType;
        }

        public int getAmount(){
            return zAmount;
        }
    }
}
