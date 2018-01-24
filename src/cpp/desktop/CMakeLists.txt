cmake_minimum_required(VERSION 3.7)

project(atomic-plugin-ads)

include_directories(../)

add_library(null_atomic_plugin_ads
    AdService.cpp
    AdBanner.cpp
    AdInterstitial.cpp
    NullAdService.cpp
    NullAdBanner.cpp
    NullAdInterstitial.cpp
    NullAdUtils.cpp
    NullAdService.h
    NullAdBanner.h
    NullAdInterstitial.h
    NullAdUtils.h
    NullAdRewardedVideo.h
    NullAdRewardedVideo.cpp
    ../AdService.h
    ../AdBanner.h
    ../AdInterstitial.h
    )
