package com.ludei.ads;

/**
 * Created by fabio on 24/01/18.
 */

public interface AdRewardedVideo {
    void setListener(RewardedVideoListener listener);

    void loadAd();

    boolean show();

    void destroy();

    public interface RewardedVideoListener {

        public void onAdLoaded();

        public void onAdOpened();

        public void onAdStarted();

        public void onAdClosed();

        public void onRewarded(RewardItem rewardItem);

        public void onAdLeftApplication();

        public void onAdFailedToLoad(int i);
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
