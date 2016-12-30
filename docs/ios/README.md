# Facebook Requirements and Set-Up [iOS]

To use this plugin you will need to make sure you've registered your Facebook app with Facebook and have an `APP_ID` [https://developers.facebook.com/apps](https://developers.facebook.com/apps).

If you plan on rolling this out on iOS, please note that you will need to ensure that you have properly set up your Native iOS App settings on the [Facebook App Dashboard](http://developers.facebook.com/apps). Please see the [Getting Started with the Facebook SDK](https://developers.facebook.com/docs/ios/getting-started/): Create a Facebook App section, for more details on this.

### Install

This plugin requires [Cordova CLI](http://cordova.apache.org/docs/en/3.5.0/guide_cli_index.md.html).

To install the plugin in your app, execute the following (replace variables where necessary):

```sh
# Create initial Cordova app
$ cordova create myApp
$ cd myApp/
$ cordova platform add ios

# Remember to replace APP_ID and APP_NAME variables
$ cordova plugin add cordova-plugin-facebook4 --save --variable APP_ID="123456789" --variable APP_NAME="myApplication"
```

**Note: "In case of iOS 10, it requires additional entries in the Content-Security-Policy meta tag, namely gap://ready. After adding this, Content-Security-Policy should look like this:"**

```sh
<meta http-equiv="Content-Security-Policy" content="default-src * gap://ready; style-src 'self' 'unsafe-inline'; img-src 'self' data:; script-src * 'unsafe-inline' 'unsafe-eval'">
```