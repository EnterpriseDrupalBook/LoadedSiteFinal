<?php
/**
 * @file
 * k_b_rules.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function k_b_rules_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'customers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Customers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Customers';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: Interests */
  $handler->display->display_options['fields']['field_interests']['id'] = 'field_interests';
  $handler->display->display_options['fields']['field_interests']['table'] = 'field_data_field_interests';
  $handler->display->display_options['fields']['field_interests']['field'] = 'field_interests';
  $handler->display->display_options['fields']['field_interests']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_interests']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_interests']['delta_offset'] = '0';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    4 => '4',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'customers';

  /* Display: Rules */
  $handler = $view->new_display('views_rules', 'Rules', 'views_rules_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['rules_variables'] = array(
    'name' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'text',
      'label' => 'Name',
      'name' => 'name',
    ),
    'field_interests' => array(
      'enabled' => 1,
      'rendered' => 1,
      'type' => 'text',
      'label' => 'Interest',
      'name' => 'interests',
    ),
    'mail' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'text',
      'label' => 'E-mail',
      'name' => 'mail',
    ),
  );
  $export['customers'] = $view;

  $view = new view();
  $view->name = 'specials_to_be_emailed';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Specials to be emailed';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Specials to be emailed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Customers */
  $handler->display->display_options['fields']['field_customers']['id'] = 'field_customers';
  $handler->display->display_options['fields']['field_customers']['table'] = 'field_data_field_customers';
  $handler->display->display_options['fields']['field_customers']['field'] = 'field_customers';
  $handler->display->display_options['fields']['field_customers']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_customers']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  /* Field: Content: Send Email */
  $handler->display->display_options['fields']['field_send_email']['id'] = 'field_send_email';
  $handler->display->display_options['fields']['field_send_email']['table'] = 'field_data_field_send_email';
  $handler->display->display_options['fields']['field_send_email']['field'] = 'field_send_email';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'special' => 'special',
  );
  /* Filter criterion: Content: Send Email (field_send_email) */
  $handler->display->display_options['filters']['field_send_email_value']['id'] = 'field_send_email_value';
  $handler->display->display_options['filters']['field_send_email_value']['table'] = 'field_data_field_send_email';
  $handler->display->display_options['filters']['field_send_email_value']['field'] = 'field_send_email_value';
  $handler->display->display_options['filters']['field_send_email_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Start Date -  start date (field_start_date) */
  $handler->display->display_options['filters']['field_start_date_value']['id'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['table'] = 'field_data_field_start_date';
  $handler->display->display_options['filters']['field_start_date_value']['field'] = 'field_start_date_value';
  $handler->display->display_options['filters']['field_start_date_value']['operator'] = '<=';
  $handler->display->display_options['filters']['field_start_date_value']['default_date'] = 'now + 7 days';
  $handler->display->display_options['filters']['field_start_date_value']['year_range'] = '-1:+1';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'specials-to-be-emailed';

  /* Display: Rules */
  $handler = $view->new_display('views_rules', 'Rules', 'views_rules_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['rules_variables'] = array(
    'field_customers' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'text',
      'label' => 'Customer Email',
      'name' => 'field_customers',
    ),
    'body' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'text',
      'label' => 'Body',
      'name' => 'body',
    ),
    'field_send_email' => array(
      'enabled' => 1,
      'rendered' => 0,
      'type' => 'text',
      'label' => 'Send Email',
      'name' => 'field_send_email',
    ),
  );
  $export['specials_to_be_emailed'] = $view;

  return $export;
}
