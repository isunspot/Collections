#!/bin/sh

sudo grep -n heyu /var/log/secure |grep su
echo '-----------------------------'
sudo grep -n heyu /var/log/messages |grep su
