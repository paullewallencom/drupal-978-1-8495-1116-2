<?php

/**
 *  @file
 *  Provides the administrative related functions for the Facebook Feed Module.
 */
 /**
  * Defines the Facebook Feeds Block admin settings form
  */
  
function fb_feed_block_settings_form() {
	$form = array();
	$form['fb_feed_block_maxposts'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of Facebook Feed Items to show'),
    '#description' => t('The maximum number of Facebook Feed item nodes to show in the Facebook Feeds Block.'),
    '#default_value' => variable_get('fb_feed_block_maxposts', 3),
    '#size' => 2,
    '#maxlength' => 2,
    '#required' => TRUE,
  );
  
  $form['fb_feed_block_types'] = array(
	'#title' => t('The content types to enable FB Feed Block for'),
    '#description' => t('On the specified content types a FB Feed Block option will be enabled.'),
    '#type' => 'checkboxes',
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('fb_feed_block_types', array()),
    '#required' => TRUE,
  );

  return system_settings_form($form);
}

function fb_feed_block_settings_form_validate($form, &$form_state) {
  $maxposts = $form_state['values']['fb_feed_block_maxposts'];
  if (!is_numeric($maxposts)) {
    form_set_error('fb_feed_block_maxposts', t('You must enter an integer for the maximum number of links.'));
  }
  else if ($maxposts <= 0) {
    form_set_error('fb_feed_block_maxposts', t('Maximum number of links must be positive.'));
  }
}

 
 