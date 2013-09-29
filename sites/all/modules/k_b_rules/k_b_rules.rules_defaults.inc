<?php
/**
 * @file
 * k_b_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function k_b_rules_default_rules_configuration() {
  $items = array();
  $items['rules_special_email_sending'] = entity_import('rules_config', '{ "rules_special_email_sending" : {
      "LABEL" : "Special Email Sending",
      "PLUGIN" : "rule",
      "REQUIRES" : [ "rules" ],
      "USES VARIABLES" : {
        "name" : { "label" : "Name", "type" : "text" },
        "interests" : { "label" : "Interests", "type" : "text" },
        "email" : { "label" : "Email", "type" : "text" },
        "specialtag" : { "label" : "Special Tag", "type" : "text" },
        "cusomersinterested" : { "label" : "Customers Interested", "type" : "list\\u003Ctext\\u003E" }
      },
      "IF" : [
        { "text_matches" : { "text" : [ "interests" ], "match" : [ "specialtag" ] } }
      ],
      "DO" : [
        { "drupal_message" : { "message" : "[preference:value]\\r\\n[specialtag:value]" } },
        { "list_add" : { "list" : [ "cusomersinterested" ], "item" : [ "email" ], "unique" : 1 } }
      ],
      "PROVIDES VARIABLES" : [ "cusomersinterested" ]
    }
  }');
  $items['rules_specials_emailer'] = entity_import('rules_config', '{ "rules_specials_emailer" : {
      "LABEL" : "Specials Emailer",
      "PLUGIN" : "reaction rule",
      "WEIGHT" : "1",
      "REQUIRES" : [ "views_rules", "rules" ],
      "ON" : [ "cron" ],
      "DO" : [
        { "VIEW LOOP" : {
            "VIEW" : "specials_to_be_emailed",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : {
              "field_customers" : { "field_customers" : "Customer Email" },
              "body" : { "body" : "Body" },
              "field_send_email" : { "field_send_email" : "Send Email" }
            },
            "DO" : [
              { "mail" : {
                  "to" : [ "field-customers" ],
                  "subject" : "Blabla",
                  "message" : "Blabla [body:value]",
                  "from" : "Blabla",
                  "language" : [ "" ]
                }
              }
            ]
          }
        },
        { "VIEW LOOP" : {
            "VIEW" : "specials_to_be_emailed",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : {
              "field_customers" : { "field_customers" : "Customer Email" },
              "body" : { "body" : "Body" },
              "field_send_email" : { "field_send_email" : "Send Email" }
            },
            "DO" : [ { "data_set" : { "data" : [ "field-send-email" ], "value" : "No" } } ]
          }
        }
      ]
    }
  }');
  $items['rules_specials_emailing'] = entity_import('rules_config', '{ "rules_specials_emailing" : {
      "LABEL" : "Specials Email List",
      "PLUGIN" : "reaction rule",
      "REQUIRES" : [ "rules", "views_rules" ],
      "ON" : [ "node_insert", "node_update" ],
      "IF" : [
        { "node_is_of_type" : { "node" : [ "node" ], "type" : { "value" : { "special" : "special" } } } },
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_customers" } }
      ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-customers" ], "value" : { "value" : [] } } },
        { "VIEW LOOP" : {
            "VIEW" : "customers",
            "DISPLAY" : "views_rules_1",
            "ROW VARIABLES" : {
              "name" : { "name" : "Name" },
              "interests" : { "interests" : "Interests" },
              "mail" : { "mail" : "E-mail" }
            },
            "DO" : [
              { "LOOP" : {
                  "USING" : { "list" : [ "node:field-specialtags" ] },
                  "ITEM" : { "specialtag" : "Current list item" },
                  "DO" : [
                    { "component_rules_special_email_sending" : {
                        "USING" : {
                          "name" : [ "name" ],
                          "interests" : [ "interests" ],
                          "email" : [ "mail" ],
                          "specialtag" : [ "specialtag:name" ],
                          "cusomersinterested" : [ "node:field-customers" ]
                        },
                        "PROVIDE" : { "cusomersinterested" : { "cusomersinterested" : "Customers Interested" } }
                      }
                    }
                  ]
                }
              }
            ]
          }
        },
        { "LOOP" : {
            "USING" : { "list" : [ "node:field-customers" ] },
            "ITEM" : { "list_item" : "Current list item" },
            "DO" : [
              { "mail" : {
                  "to" : "[list-item:value]",
                  "subject" : "Blabla",
                  "message" : [ "node:body:value" ],
                  "from" : "Blabla",
                  "language" : [ "" ]
                }
              }
            ]
          }
        }
      ]
    }
  }');
  return $items;
}
