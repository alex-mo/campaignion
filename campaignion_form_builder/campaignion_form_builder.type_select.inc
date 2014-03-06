<?php

/**
 * Invoked by campaignion_form_builder_form_builder_types().
 */
function _campaignion_form_builder_form_builder_types_select() {
  $fields = array();

  $ae_select = array(
    'properties' => array(
      'default_value',
      'options',
      'multiple',
    ),
    'default'       => _form_builder_webform_default('select', array('aslist' => TRUE, 'multiple' => FALSE)),
    'palette_group' => 'advocacy_engine',
    'unique'        => TRUE,
  );


  $fields['form_of_address'] = array(
    'title'  => t('Form of address'),
    'weight' => -82,
  ) + $ae_select;
  $fields['form_of_address']['properties'][] = 'other_option';
  $fields['form_of_address']['properties'][] = 'other_text';
  $fields['form_of_address']['default']['#options']       = array('fam' => t('Family'), 'mrs' => t('Mrs'), 'mr' => t('Mr'));
  $fields['form_of_address']['default']['#default_value'] = '%get[p1]';
  $fields['form_of_address']['default']['#title']         = t('Form of Address');
  $fields['form_of_address']['default']['#other_option']  = TRUE;
  $fields['form_of_address']['default']['#form_builder']['element_type'] = 'select';

  $fields['gender'] = array(
    'title'  => t('Gender'),
    'weight' => -81,
  ) + $ae_select;
  $fields['gender']['default']['#options']       = array('f' => t('female'), 'm' => t('male'), 'o' => t('other'));
  $fields['gender']['default']['#default_value'] = '%get[p2]';
  $fields['gender']['default']['#title']         = t('Gender');
  $fields['gender']['default']['#form_builder']['element_type'] = 'select';

  $fields['country'] = array(
    'title'  => t('Country'),
    'weight' => -73,
  ) + $ae_select;
  include_once(drupal_get_path('module', 'webform') . '/includes/webform.options.inc');
  $country_list = webform_options_countries(NULL, NULL, NULL, NULL);
  $fields['country']['default']['#options']       = $country_list;
  $fields['country']['default']['#default_value'] = '%get[p9]';
  $fields['country']['default']['#title']         = t('Country');
  $fields['country']['default']['#form_builder']['element_type'] = 'select';

  $fields['email_newsletter'] = array(
    'title'  => t('Newsletter'),
    'weight' => -69,
  ) + $ae_select;
  $fields['email_newsletter']['default']['#options']       = array('1' => t('Yes, I\'d like to get email newsletters'));
  $fields['email_newsletter']['default']['#default_value'] = 1;
  $fields['email_newsletter']['default']['#title']         = t('Email Newsletter');
  $fields['email_newsletter']['default']['#type']          = 'checkboxes';
  $fields['email_newsletter']['default']['#form_builder']['element_type'] = 'checkboxes';

  $fields['direct_mail_newsletter'] = array(
    'title'  => t('Direct Mail'),
    'weight' => -68,
  ) + $ae_select;
  $fields['direct_mail_newsletter']['default']['#options']       = array('1' => t('Yes, I\'d like to get direct mail newsletters'));
  $fields['direct_mail_newsletter']['default']['#default_value'] = 1;
  $fields['direct_mail_newsletter']['default']['#title']         = t('Direct Mail Newsletter');
  $fields['direct_mail_newsletter']['default']['#type']          = 'checkboxes';
  $fields['email_newsletter']['default']['#form_builder']['element_type'] = 'checkboxes';

  $fields['state'] = array(
    'title'  => t('State'),
    'weight' => -73,
  ) + $ae_select;
  $fields['state']['default']['#options'] = array(
    'W'  => t('Wien'),
    'N'  => t('Niederösterreich'),
    'O'  => t('Oberösterreich'),
    'S'  => t('Salzburg'),
    'T'  => t('Tirol'),
    'V'  => t('Vorarlberg'),
    'B'  => t('Burgenland'),
    'St' => t('Steiermark'),
    'K'  => t('Kärnten'),
  );
  $fields['state']['default']['#title']         = t('State');
  $fields['state']['default']['#default_value'] = '%get[p10]';
  $fields['state']['default']['#form_builder']['element_type'] = 'select';

  if (_campaignion_form_builder_is_donation() == TRUE) {
    $fields['donation_interval'] = array(
      'title'         => t('Donation interval'),
      'weight'        => -98,
    ) + $ae_select;
    $fields['donation_interval']['palette_group'] = 'donation';
    $fields['donation_interval']['default']['#options']       = array('1' => t('only once'), 'm' => t('monthly'), 'y' => t('yearly'));
    $fields['donation_interval']['default']['#default_value'] = 'm';
    $fields['donation_interval']['default']['#title']         = t('Donation interval');
    $fields['donation_interval']['default']['#required'] = TRUE;
  }

  return $fields;
}